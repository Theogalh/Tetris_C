/*
** algo_rotate.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Wed Mar  2 12:14:43 2016 Robin Partouche
** Last update Thu Mar  3 18:30:21 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

int	rotate_nord_est(int **tmp_terran, t_coord crd,
			t_pos center, int **terran)
{
  if (terran[crd.i][crd.j] == center.id_bloc &&
      (crd.i < center.x && crd.j >= center.y))
    {
      if (center.x + (crd.j - center.y) <= 0 ||
          center.y + (center.x - crd.i) <= 0 ||
          center.x + (crd.j - center.y) > center.line ||
	  center.y + (center.x - crd.i) > center.line)
	return (0);
      if (terran[center.x + (crd.j - center.y)]
          [center.y + (center.x - crd.i)] != center.id_bloc
          && terran[center.x + (crd.j - center.y)]
	  [center.y + (center.x - crd.i)] != 0)
	return (0);
      tmp_terran[center.x + (crd.j - center.y)]
      [center.y + (center.x - crd.i)] = center.id_bloc;
    }
  else if (terran[crd.i][crd.j] == center.id_bloc &&
	   (crd.i == center.x && crd.j == center.y))
    tmp_terran[crd.i][crd.j] = center.id_bloc;
  return (1);
}

int	rotate_sud_ouest(int **tmp_terran,
			 t_coord crd, t_pos center, int **terran)
{
  if (terran[crd.i][crd.j] == center.id_bloc &&
      (crd.i > center.x && crd.j <= center.y))
    {
      if (center.x - (center.y - crd.j) <= 0 || center.y +
	  (crd.i - center.x) <= 0 ||
	  center.x - (center.y - crd.j) > center.line ||
	  center.y + (crd.i - center.x) > center.line)
	return (0);
      if (tmp_terran[center.x - (center.y - crd.j)]
	  [center.y - (crd.i - center.x)] != center.id_bloc
	  && tmp_terran[center.x - (center.y - crd.j)]
	  [center.y - (crd.i - center.x)] != 0)
	return (0);
      tmp_terran[center.x - (center.y - crd.j)]
      [center.y - (crd.i - center.x)] = center.id_bloc;
    }
  else
    return (rotate_nord_est(tmp_terran, crd, center, terran));
  return (1);
}

int	rotate_sud_est(int **tmp_terran, t_coord crd,
		       t_pos center, int **terran)
{
  if (terran[crd.i][crd.j] == center.id_bloc &&
      (crd.i >= center.x && crd.j > center.y))
    {
      if (center.x + (crd.j - center.y) <= 0 ||
	  center.y - (crd.i - center.x) <= 0 ||
	  center.x + (crd.j - center.y) > center.line ||
	  center.y - (crd.i - center.x) > center.line)
	return (0);
      if (tmp_terran[center.x + (crd.j - center.y)][center.y -
	  (crd.i - center.x)] != center.id_bloc && tmp_terran[center.x +
	  (crd.j - center.y)][center.y - (crd.i - center.x)] != 0)
	return (0);
      tmp_terran[center.x + (crd.j - center.y)]
      [center.y - (crd.i - center.x)] = center.id_bloc;
    }
  else
    return (rotate_sud_ouest(tmp_terran, crd, center, terran));
  return (1);
}

int	rotate_nord_ouest(int **tmp_terran, t_coord crd,
			  t_pos center, int **terran)
{
  if (terran[crd.i][crd.j] == center.id_bloc && (crd.i <= center.x
      && crd.j < center.y))
    {
      if (center.x - (center.y - crd.j) <= 0 ||
	  center.y + (center.x - crd.i) <= 0 ||
	  center.x - (center.y - crd.j) > center.line ||
	  center.y + (center.x - crd.i) > center.line)
	return (0);
      if (tmp_terran[center.x - (center.y - crd.j)]
	  [center.y + (center.x - crd.i)] != center.id_bloc
	  && tmp_terran[center.x - (center.y - crd.j)]
	  [center.y + (center.x - crd.i)] != 0)
	return (0);
      tmp_terran[center.x - (center.y - crd.j)]
      [center.y + (center.x - crd.i)] = center.id_bloc;
    }
  else
    return (rotate_sud_est(tmp_terran, crd, center, terran));
  return (1);
}
