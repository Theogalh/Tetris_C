/*
** print2.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Feb 25 11:34:12 2016 Robin Partouche
** Last update Sat Mar 19 20:06:55 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	print_sup_next_tetro(t_game *tetris, int i, int j)
{
  while (i != tetris->larg_max + 4)
    {
      while (j != tetris->long_max + 3)
	{
	  if (i == 0 || i == tetris->larg_max + 3
	      || j == 0 || j == tetris->long_max + 2)
	    {
	      print_color(8, i, (j + tetris->info.col) * 2 + 5);
	      print_color(8, i, (j + tetris->info.col) * 2 + 6);
	    }
	  else
	    {
	      print_color(0, i, (j + tetris->info.col) * 2 + 5);
	      print_color(0, i, (j + tetris->info.col) * 2 + 6);
	    }
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
}

void	print_next_tetro(t_game *tetris, int i_t, int j_t, int color)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tetris->tetro[tetris->next_id - 2].img[i] != 0)
    {
      while (tetris->tetro[tetris->next_id - 2].img[i][j] != 0)
	{
	  if (tetris->tetro[tetris->next_id - 2].img[i][j] == '*')
	    {
	      print_color(color, tetris->long_max / 2 - i_t / 2 + i + 2,
	      (j + tetris->info.col) * 2 + 12 - tetris->larg_max / 2 - j_t / 2);
	      print_color(color, tetris->long_max / 2 - i_t / 2 + i + 2,
	      (j + tetris->info.col) * 2 + 13 - tetris->larg_max / 2 - j_t / 2);
	    }
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
}
