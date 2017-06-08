/*
** tetro_files.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Mar 18 17:35:35 2016 Robin Partouche
** Last update Sun Mar 20 17:42:30 2016 Robin Partouche
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "info.h"
#include "game.h"
#include "ls_dir.h"

int	length_buff(int fd)
{
  char	*buff;
  int	len;
  int	total_length;

  total_length = 0;
  len = 1;
  if ((buff = malloc(sizeof(*buff) * (1024 + 1))) == NULL)
    exit(1);
  while ((len = read(fd, buff, 1024)) > 0)
    {
      if (len != 0)
	total_length = len + total_length;
    }
  free(buff);
  return (total_length);
}

int		get_tetro_map(t_game *tetris, char *file, int arg)
{
  t_tetro_door	tdoor;
  char		**map;

  tdoor.i = 0;
  tdoor.j = 0;
  tdoor.f = 0;
  tdoor.door = 0;
  map = init_map(tetris->tetro[arg].i_t + 1, tetris->tetro[arg].j_t + 1);
  while (file[tdoor.i] != 0)
    tetro_while(&tdoor, file, map);
  if (tdoor.door != 0)
    map[tdoor.door - 1][tdoor.f] = 0;
  map[tdoor.door - 1][tdoor.j] = file[tdoor.i];
  map[tdoor.door] = 0;
  tetris->tetro[arg].img = map;
  return (0);
}

int	tetro_at_tab(t_game *tetris, char *file, int arg, char *name)
{
  int	tmp;

  tetris->tetro[arg].name = my_tetro_name(name);
  if (get_tetro_info(tetris, file, arg, 0) == 1)
    return (1);
  if (tetris->tetro[arg].i_t >= tetris->info.col ||
      tetris->tetro[arg].i_t <= 0)
    return (1);
  if (tetris->tetro[arg].i_t > tetris->larg_max)
    tetris->larg_max = tetris->tetro[arg].i_t;
  if (tetris->tetro[arg].j_t > tetris->long_max)
    tetris->long_max = tetris->tetro[arg].j_t;
  if (tetris->tetro[arg].j_t >= tetris->info.line ||
      tetris->tetro[arg].j_t <= 0)
    return (1);
  if (tetris->tetro[arg].color > 7 || tetris->tetro[arg].color <= -1)
    return (1);
  if ((get_tetro_map(tetris, file, arg)) == 1)
    return (1);
  if ((tmp = (verif_map(tetris->tetro[arg].img, tetris->tetro[arg].i_t,
			tetris->tetro[arg].j_t, 0))) == 1)
    return (1);
  lock_tetro(tetris, tetris->tetro[arg].img, 0, arg);
  return (0);
}

void		keep_tetro(t_game *tetris, DIR *fd_dir)
{
  struct dirent *buffer;
  char		*file;
  int		fd;
  int		length;
  int		arg;

  arg = 0;
  while ((buffer = fs_read_dir(fd_dir)) != NULL)
    {
      if (my_str_found(buffer->d_name, ".tetrimino") == 1)
	{
	  fd = fs_open(my_strcat("tetriminos/", buffer->d_name));
	  length = length_buff(fd);
	  fs_close(fd);
	  fd = fs_open(my_strcat("tetriminos/", buffer->d_name));
	  file = fs_read(fd, length);
	  if ((tetro_at_tab(tetris, file, arg, buffer->d_name)) == 1)
	    tetris->tetro[arg].error = 1;
	  else
	    tetris->tetro[arg].error = 0;
	  keep_tetro_mid(&arg, file, fd);
	}
    }
  keep_tetro_end(tetris, buffer, fd_dir, arg);
}

void	verif_dir(char *file)
{
  DIR   *test;

  if ((test = opendir(file)) == NULL)
    {
      my_putstr("Micheltris: cannot access tetriminos directory's .\n");
      exit(1);
    }
}
