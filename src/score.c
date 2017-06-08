/*
** score.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Mar 20 20:50:37 2016 Robin Partouche
** Last update Sun Mar 20 21:57:55 2016 Robin Partouche
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

void	create_high_score(t_game *tetris, int score)
{
  int	fd;

  tetris->hscore = score;
  fd = fs_create("hscore");
  my_putfd('0', fd);
  fs_close(fd);
}

void	change_hscore(int fd, int score)
{
  if (score >= 10)
    {
      change_hscore(fd, score / 10);
      my_putfd(score % 10 + 48, fd);
    }
  else
    my_putfd(score + 48, fd);
}

void	refresh_hscore(t_game *tetris)
{
  char	*file;
  int	fd;
  int	length;

  if ((fd = fs_open("hscore")) == 0)
    {
      create_high_score(tetris, tetris->score);
      fd = fs_open("hscore");
    }
  length = length_buff(fd);
  fs_close(fd);
  fd = fs_open("hscore");
  file = fs_read(fd, length);
  if (my_getnbr(file) < tetris->score)
    {
      fs_close(fd);
      fd = fs_open("hscore");
      change_hscore(fd, tetris->score);
    }
  free(file);
  fs_close(fd);
}

void	init_high_score(t_game *tetris)
{
  char	*file;
  int	fd;
  int	length;
  int	hscore;

  if ((fd = fs_open("hscore")) == 0)
    create_high_score(tetris, 0);
  else
    {
      length = length_buff(fd);
      fs_close(fd);
      fd = fs_open("hscore");
      file = fs_read(fd, length);
      if ((hscore = my_getnbr(file)) <= -1)
	tetris->hscore = 0;
      else
	tetris->hscore = hscore;
      free(file);
      fs_close(fd);
    }
}
