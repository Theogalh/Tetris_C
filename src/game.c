/*
** game.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Feb 23 15:00:41 2016 Robin Partouche
** Last update Sun Mar 20 22:14:03 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	validate_refresh(t_game *tetris, int lock)
{
  int	i;
  int	j;

  i = tetris->info.line;
  j = tetris->info.col;
  while (i != 0)
    {
      while (j != 0)
	{
	  while_refresh(lock, tetris, i, j);
	  j = j - 1;
	}
      j = tetris->info.col + 1;
      i = i - 1;
    }
  tetris->center.x = tetris->center.x + 1;
}

int	refresh_turn(t_game *tetris)
{
  int	i;
  int	j;

  i = tetris->info.line;
  j = tetris->info.col;
  while (i != 0)
    {
      while (j != 0)
	{
	  if ((tetris->terran[i + 1][j] == 1 || tetris->terran[i + 1][j] < -1)
	      && tetris->terran[i][j] > 1)
	    return (1);
	  j = j - 1;
	}
      j = tetris->info.col + 1;
      i = i - 1;
    }
  return (0);
}

int	**place_bloc(int **terran, t_game *tetris, int rand, int i)
{
  int	j;

  j = 0;
  while (tetris->tetro[tetris->id_bloc - 2].img[i] != 0)
    {
      while (tetris->tetro[tetris->id_bloc - 2].img[i][j] != 0)
	{
	  if (tetris->terran[i + 1][j + rand + 1] == 1 ||
	      tetris->terran[i + 1][j + rand + 1] <= -2)
	    return (NULL);
	  if (tetris->tetro[tetris->id_bloc - 2].img[i][j] == '*')
	    terran[i + 1][j + rand + 1] = tetris->id_bloc;
	  if (i == tetris->tetro[tetris->id_bloc - 2].center.x - 1
	      && j == tetris->tetro[tetris->id_bloc - 2].center.y - 1)
	    {
	      tetris->center.x = i + 1;
	      tetris->center.y = j + rand + 1;
	    }
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (terran);
}

void	create_bloc(t_game *tetris)
{
  int	rander;
  int	**tmp;
  int	ifend;

  ifend = 0;
  if (tetris->bool_bloc == 0)
    {
      get_points(tetris);
      tetris->lines_down = tetris->lines_down + 1;
      tetris->id_bloc = tetris->next_id;
      tetris->next_id = rand() % tetris->arg + 2;
      rander = tetris->info.col - tetris->tetro[tetris->id_bloc - 2 ].j_t;
      while ((tmp = place_bloc(prepare_terran(tetris, my_double_str_int_dup
	     (tetris->terran, tetris->info.col, tetris->info.line)),
			       tetris, rand() % rander, 0)) == NULL)
	{
	  rander = tetris->info.col - tetris->tetro[tetris->next_id - 2].j_t;
	  ifend = ifend + 1;
	  if (ifend >= 60)
	    end(tetris);
	}
      tetris->terran = tmp;
      create_bloc_next(tetris);
    }
}

void	value_to_terran(t_game *tetris)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i != tetris->info.line + 2)
    {
      while (j != tetris->info.col + 2)
	{
	  if (j == 0 || i == 0 || j + 1 == tetris->info.col + 2
	      || i + 1 == tetris->info.line + 2)
	    tetris->terran[i][j] = 1;
	  else
	    tetris->terran[i][j] = 0;
	  j = j + 1;
	}
      tetris->terran[i][j] = -1;
      j = 0;
      i = i + 1;
    }
  tetris->terran[i] = NULL;
}
