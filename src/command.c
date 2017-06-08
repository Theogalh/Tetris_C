/*
** command.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Wed Feb 24 10:41:47 2016 Robin Partouche
** Last update Tue Mar 22 17:36:37 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

int		**move_up(int **tmp_terran, t_info info, t_pos center, int **terran)
{
  int		i;
  int		j;
  t_coord	crd;

  i = info.line;
  j = info.col;
  while (i != 0)
    {
      while (j != 0)
	{
	  crd.i = i;
	  crd.j = j;
	  if (rotate_nord_ouest(tmp_terran, crd, center, terran) == 0)
	    return (NULL);
	  j = j - 1;
	}
      j = info.col;
      i = i - 1;
    }
  return (tmp_terran);
}

int	**move_right(int **terran, int id_bloc, int col, int line)
{
  int	i;
  int	j;

  i = line;
  j = col;
  while (i != 0)
    {
      while (j != 0)
	{
	  if (terran[i][j] == id_bloc &&
	      (terran[i][j + 1] == 0 || terran[i][j + 2] >= 2))
	    {
	      terran[i][j + 1] = id_bloc;
	      terran[i][j] = 0;
	    }
	  else if (terran[i][j] == id_bloc)
	    return (NULL);
	  j = j - 1;
	}
      j = col;
      i = i - 1;
    }
  return (terran);
}

int	**move_left(int **terran, int id_bloc, int col, int line)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i != line + 2)
    {
      while (j != col + 2)
	{
	  if (terran[i][j] == id_bloc &&
              (terran[i][j - 1] == 0 || terran[i][j - 1] >= 2))
	    {
	      terran[i][j - 1] = id_bloc;
	      terran[i][j] = 0;
	    }
	  else if (terran[i][j] == id_bloc)
	    return (NULL);
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (terran);
}

void	move_side2(t_game *tetris, char *input, int **tmp)
{
  if (my_str_comparate(tetris->info.turn, input) == 1)
    {
      if (tetris->tetro[tetris->id_bloc - 2].lock == 0)
	{
	  tetris->center.id_bloc = tetris->id_bloc;
	  tetris->center.line = tetris->info.line;
	  if ((tmp = move_up(prepare_terran(tetris, my_double_str_int_dup
	 (tetris->terran, tetris->info.col, tetris->info.line)),
	    tetris->info, tetris->center, tetris->terran)) != NULL)
	    tetris->terran = tmp;
	}
    }
  else if (my_str_comparate(tetris->info.drop, input) == 1)
    {
      if ((tmp = move_down(my_double_str_int_dup(tetris->terran,
	 tetris->info.col, tetris->info.line), tetris->id_bloc,
	 tetris->info.col, tetris->info.line)) != NULL)
	{
	  tetris->terran = tmp;
	  if (tetris->terran[0][0] <= 150)
	    tetris->score = tetris->score + tetris->terran[0][0] / 2;
	  tetris->center.x = tetris->center.x + tetris->terran[0][0];
	  tetris->terran[0][0] = 1;
	}
    }
}

void		move_side(t_game *tetris, char *input)
{
  int		**tmp;

  tmp = NULL;
  if (my_str_comparate(tetris->info.left, input) == 1)
    {
      if ((tmp = move_left(my_double_str_int_dup(tetris->terran,
	 tetris->info.col, tetris->info.line), tetris->id_bloc,
	 tetris->info.col, tetris->info.line)) != NULL)
	{
	  tetris->terran = tmp;
	  tetris->center.y = tetris->center.y - 1;
	}
    }
  else if (my_str_comparate(tetris->info.right, input) == 1)
    {
      if ((tmp = move_right(my_double_str_int_dup(tetris->terran,
	   tetris->info.col, tetris->info.line), tetris->id_bloc,
	   tetris->info.col, tetris->info.line)) != NULL)
	{
	  tetris->terran = tmp;
	  tetris->center.y = tetris->center.y + 1;
	}
    }
  else
    move_side2(tetris, input, tmp);
}
