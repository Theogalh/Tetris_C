/*
** get_tetro.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Mar 18 17:28:40 2016 Robin Partouche
** Last update Sun Mar 20 21:05:37 2016 Robin Partouche
*/

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"
#include "ls_dir.h"

int	get_the_nbr(char *file, int a, int i)
{
  int	tmp;
  int	nbr;

  nbr = 0;
  while (a != i)
    {
      tmp = file[a] - 48;
      if (tmp < 0 || tmp > 9)
	return (-1);
      nbr = nbr * 10 + tmp;
      a = a + 1;
    }
  return (nbr);
}

int	verif_map(char **map, int line, int col, int door)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i] != 0)
    {
      while (map[i][j] != 0)
	j = j + 1;
      if (j > col && map[i][j] == '*')
	return (1);
      if (j == col)
	door = 1;
      i = i + 1;
      j = 0;
    }
  if (door != 1)
    return (1);
  if (i != line)
    return (1);
  return (0);
}

void	give_tetro(t_game *tetris, int tmp, int door, int arg)
{
  if (door == 0)
    {
      tetris->tetro[arg].j_t = tmp;
      if (tmp % 2 == 0)
	tetris->tetro[arg].center.y = tmp / 2;
      else
	tetris->tetro[arg].center.y = tmp / 2 + 1;
    }
  else if (door == 1)
    {
      tetris->tetro[arg].i_t = tmp;
      if (tmp % 2 == 0)
	tetris->tetro[arg].center.x = tmp / 2 ;
      else
	tetris->tetro[arg].center.x = tmp / 2 + 1;
    }
  else if (door == 2)
    {
      tetris->tetro[arg].center.id_bloc = arg;
      tetris->tetro[arg].color = tmp;
    }
}

int	get_tetro_info(t_game *tetris, char *file, int arg, int i)
{
  int	door;
  int	a;
  int	tmp;

  a = 0;
  door = 0;
  while (file[i] != 0 && file[i] != '\n')
    {
      if (file[i] == ' ')
	{
	  if ((tmp = get_the_nbr(file, a, i)) == -1)
	    return (1);
	  give_tetro(tetris, tmp, door, arg);
	  door = door + 1;
	  a = i + 1;
	}
      i = i + 1;
    }
  if ((tmp = get_the_nbr(file, a, i)) == -1)
    return (1);
  give_tetro(tetris, tmp, door, arg);
  if (door != 2 || file[i] == 0)
    return (1);
  return (0);
}

void	get_tetro(t_game *tetris)
{
  DIR	*fd;

  verif_dir("tetriminos");
  fd = fs_open_dir("tetriminos");
  keep_tetro(tetris, fd);
  if (tetris->arg == 0)
    {
      my_putstr("MichelTris: Aucun tetriminos n'est valide.");
      xexit(1);
    }
  tritetro(tetris, tetris->arg);
  init_high_score(tetris);
}
