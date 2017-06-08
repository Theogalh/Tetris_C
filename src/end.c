/*
** end.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Wed Feb 24 19:09:20 2016 Robin Partouche
** Last update Sun Mar 20 21:33:41 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	print_end(t_game *tetris)
{
  init_colored();
  attron(COLOR_PAIR(15));
  refresh_score(tetris);
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 29 , "E");
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 30, "N");
  mvprintw(1 + (tetris->info.line + 2) / 2,
  (tetris->info.col * 2 + 2) / 2 + 31 , "D");
  attroff(COLOR_PAIR(15));
  refresh();
}

void	end(t_game *tetris)
{
  char	*input;
  int	len;

  if ((input = malloc(10 * sizeof(char*))) == NULL)
    xexit(1);
  print_end(tetris);
  input[0] = 0;
  refresh_hscore(tetris);
  while (1)
    {
      if (my_str_comparate(tetris->info.pause, input) == 1
	  || my_str_comparate(tetris->info.quit, input) == 1)
	{
	  endwin();
	  xexit(0);
	}
      len = read(0, input, 10);
      input[len] = 0;
    }
}
