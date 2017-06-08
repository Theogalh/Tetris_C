/*
** print.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Feb 23 09:36:48 2016 Robin Partouche
** Last update Wed Mar  2 10:30:33 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	print_score_table()
{
  int	i;

  i = 9;
  attron(COLOR_PAIR(7));
  mvprintw(8, 1, "/--------------------\\");
  mvprintw(18, 1, "\\--------------------/");
  while (i != 18)
    {
      move(i, 1);
      printw("|                    |");
      i = i + 1;
    }
  mvprintw(10, 3, "High Score");
  mvprintw(11, 3, "Score");
  mvprintw(13, 3, "Lines");
  mvprintw(14, 3, "Level");
  mvprintw(16, 3, "Timer:");
  mvprintw(22, 1, "MichelTris (c) - 2016");
  attroff(COLOR_PAIR(7));
}

void	print_logo3(t_game *tetris)
{
  color_letter(tetris);
  mvprintw(2, 19, "####");
  mvprintw(3, 19, "#  ");
  mvprintw(4, 19, "###");
  mvprintw(5, 19, "#  ");
  mvprintw(6, 19, "####");
  color_letter(tetris);
  mvprintw(2, 24, "#");
  mvprintw(3, 24, "#  ");
  mvprintw(4, 24, "#");
  mvprintw(5, 24, "#  ");
  mvprintw(6, 24, "####");
  color_off(tetris);
}

void	print_logo2(t_game *tetris)
{
  mvprintw(2, 9, " ##");
  mvprintw(3, 9, "#  #");
  mvprintw(4, 9, "#");
  mvprintw(5, 9, "#  #");
  mvprintw(6, 9, " ##");
  color_letter(tetris);
  mvprintw(2, 14, "#  #");
  mvprintw(3, 14, "#  #");
  mvprintw(4, 14, "####");
  mvprintw(5, 14, "#  #");
  mvprintw(6, 14, "#  #");
  print_logo3(tetris);
}

void	print_logo(t_game *tetris)
{
  init_colored();
  color_letter(tetris);
  mvprintw(2, 1, "#   #");
  mvprintw(3, 1, "## ##");
  mvprintw(4, 1, "#   #");
  mvprintw(5, 1, "#   #");
  mvprintw(6, 1, "#   #");
  color_letter(tetris);
  mvprintw(2, 7, "#");
  mvprintw(3, 7, "#");
  mvprintw(4, 7, "#");
  mvprintw(5, 7, "#");
  mvprintw(6, 7, "#");
  color_letter(tetris);
  print_logo2(tetris);
}

void	refresh_score(t_game *tetris)
{
  move(10, 14);
  printw("%ld", tetris->hscore);
  move(11, 14);
  printw("%ld", tetris->score);
  move(13, 14);
  printw("%ld", tetris->lines_down);
  move(14, 14);
  printw("%ld", tetris->level);
  set_time(tetris);
}
