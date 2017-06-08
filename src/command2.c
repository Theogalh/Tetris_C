/*
** command2.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Wed Mar  2 10:57:03 2016 Robin Partouche
** Last update Sun Mar 20 17:11:07 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	print_pause(t_game *tetris)
{
  init_colored();
  attron(COLOR_PAIR(15));
  refresh_score(tetris);
  tetris->pause_time = time(NULL) + tetris->pause_time;
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 28 , "P");
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 29, "A");
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 30 , "U");
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 31 , "S");
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 32 , "E");
  attroff(COLOR_PAIR(15));
  refresh();
}

void	pause_game(t_game *tetris, char *input)
{
  int	len;

  if (my_str_comparate(tetris->info.pause, input) == 1)
    {
      print_pause(tetris);
      input[0] = 0;
      while (my_str_comparate(input, tetris->info.pause) != 1)
	{
	  len = read(0, input, 10);
	  input[len] = 0;
	}
      tetris->pause_time = tetris->pause_time - time(NULL);
    }
}

int	test_down(int **terran, int i, int j, int id_bloc)
{
  int	h;

  h = 0;
  while (terran[i + 1 + h][j] == 0 || terran[i + 1 + h][j] == id_bloc)
    {
      h = h + 1;
    }
  return (h);
}

int	verif_down(int **terran, int id_bloc, int col, int line)
{
  int	i;
  int	j;
  int	f;
  int	tmp;

  i = 0;
  j = 0;
  f = 1000;
  while (i != line + 2)
    {
      while (j != col + 2)
	{
	  if (terran[i][j] == id_bloc)
	    {
	      if ((tmp = test_down(terran, i, j, id_bloc)) < f)
		f = tmp;
	    }
	  j = j + 1;
	}
      j = 0;
      i = i + 1;
    }
  return (f);
}

int	**move_down(int **terran, int id_bloc, int col, int line)
{
  int	i;
  int	j;
  int	f;

  i = line;
  j = col;
  f = verif_down(terran, id_bloc, col, line);
  while (i != 0)
    {
      while (j != 0)
	{
	  if (terran[i][j] == id_bloc)
	    {
	      terran[i][j] = 0;
	      terran[i + f][j] = id_bloc;
	    }
	  j = j - 1;
	}
      j = col;
      i = i - 1;
    }
  terran[0][0] = f;
  return (terran);
}
