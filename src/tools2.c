/*
** tools2.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Feb 25 11:14:11 2016 Robin Partouche
** Last update Sun Mar 20 16:29:12 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	set_time(t_game *tetris)
{
  if (tetris->time == 60)
    {
      tetris->time = 0;
      tetris->mtime = tetris->mtime + 1;
    }
  move(16, 14);
  if (tetris->mtime <= 9)
    printw("0%ld:", tetris->mtime);
  else
    printw("%ld:", tetris->mtime);
  move(16, 17);
  if (tetris->time <= 9)
    printw("0%ld", tetris->time);
  else
    printw("%ld", tetris->time);
}

void	my_put2int(int **str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != NULL)
    {
      while (str[i][j] != -1)
	{
	  mvprintw(i + 1, j + 80, "%d", str[i][j]);
	  j = j + 1;
	}
      i = i + 1;
      j = 0;
    }
}

int	**prepare_terran(t_game *tetris, int **terran)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (terran[i] != NULL)
    {
      while (terran[i][j] != -1)
	{
	  if (terran[i][j] == tetris->id_bloc)
	    terran[i][j] = 0;
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (terran);
}

void	my_put2str(char **str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != NULL)
    {
      while (str[i][j] != '\0')
	{
	  my_putchar(str[i][j]);
	  j = j + 1;
	}
      my_putchar('\n');
      i = i + 1;
      j = 0;
    }
}
