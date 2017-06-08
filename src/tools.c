/*
** tools.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Feb 23 11:05:58 2016 Robin Partouche
** Last update Sat Mar 19 00:35:17 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	*init_map(int rows, int cols)
{
  int	i;
  void	**map;

  i = 0;
  if ((map = malloc(sizeof(void**) * ((rows * cols) + 1))) == NULL)
    exit(1);
  while (i != rows)
    {
      if ((map[i] = malloc(sizeof(void*) * (cols + 1))) == NULL)
	exit(1);
      i = i + 1;
    }
  return (map);
}

void	check_nbr_put_t(int **str, t_game *tetris, int *i, int *j)
{
  int	h;

  h = *j * 2;
  if (str[*i][*j] == 1)
    {
      print_color(8, *i, h);
      print_color(8, *i, h + 1);
    }
  else if (str[*i][*j] > 1)
    {
      print_color(tetris->tetro[str[*i][*j] - 2].color, *i, h);
      print_color(tetris->tetro[str[*i][*j] - 2].color, *i, h + 1);
    }
  else if (str[*i][*j] < 0)
    {
      print_color(tetris->tetro[str[*i][*j] * -1 - 2].color, *i, h);
      print_color(tetris->tetro[str[*i][*j] * -1 - 2].color, *i, h + 1);
    }
  else
    {
      print_color(0, *i, h);
      print_color(0, *i, h + 1);
    }
  *j = *j + 1;
}

void	my_put_t_int(int **str, t_game *tetris)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  init_colored();
  while (str[i] != NULL)
    {
      while (str[i][j] != -1)
	check_nbr_put_t(str, tetris, &i, &j);
      i = i + 1;
      j = 0;
    }
}

int	**my_double_str_int_dup(int **str, int col, int line)
{
  int	i;
  int	**new_str;

  i = 0;
  line = line + 2;
  col = col + 2;
  if ((new_str = malloc(sizeof(int**) *
     (((line  + 2 )* (col + 2)) + 1))) == NULL)
    xexit(1);
  while (i != line)
    {
      new_str[i] = my_str_int_dup(str[i], col);
      i = i + 1;
    }
  new_str[i] = NULL;
  return (new_str);
}
