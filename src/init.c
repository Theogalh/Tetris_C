/*
** init.c for init in /home/thomas/git/PSU_2015_tetris
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Feb 22 16:42:34 2016 thomas
** Last update Sat Mar 19 18:59:14 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	init_info(t_info *info, char *binary_name)
{
  info->col = 10;
  info->line = 20;
  info->next = 0;
  info->level = 0;
  info->left = NULL;
  info->right = NULL;
  info->turn = NULL;
  info->drop = NULL;
  info->quit = NULL;
  info->pause = NULL;
  info->map = NULL;
  info->ymax = 0;
  info->xmax = 0;
  info->debug = 0;
  info->binary_name = binary_name;
}

void	init_game(t_game *tetris)
{
  tetris->pause_time = 0;
  tetris->score = 0;
  tetris->hscore = 98678;
  tetris->stock_time = time(NULL);
  tetris->lines_down = 0;
  tetris->level = tetris->info.level;
  tetris->time = 1;
  tetris->mtime = 0;
  tetris->color = 1;
  tetris->id_bloc = 1;
  tetris->bool_bloc = 0;
  tetris->down_time = 15000 - tetris->info.level * 500;
  tetris->rand_tetro = 0;
  tetris->line_to_level = 0;
  tetris->larg_max = 0;
  tetris->long_max = 0;
}

void		init_base(t_game *tetris)
{
  init_game(tetris);
  if ((tetris->tetro = malloc(sizeof(void**) *
     ((tetris->info.line * tetris->info.col) + 1))) == NULL)
    exit(1);
}

void	init_terran(t_game *tetris)
{
  int	i;

  i = 0;
  if ((tetris->terran = malloc(sizeof(int**) *
     (((tetris->info.line  + 2 )* (tetris->info.col + 2)) + 1))) == NULL)
    exit(1);
  while (i != tetris->info.line + 2)
    {
      if ((tetris->terran[i] = malloc(sizeof(int*) *
	 (tetris->info.col + 3))) == NULL)
	exit(1);
      i = i + 1;
    }
  value_to_terran(tetris);
}

void	init_colored()
{
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(8, COLOR_WHITE, COLOR_WHITE);
  init_pair(9, COLOR_WHITE, COLOR_YELLOW);
  init_pair(10, COLOR_WHITE, COLOR_GREEN);
  init_pair(11, COLOR_WHITE, COLOR_BLUE);
  init_pair(12, COLOR_WHITE, COLOR_RED);
  init_pair(13, COLOR_WHITE, COLOR_CYAN);
  init_pair(14, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(15, COLOR_BLACK, COLOR_WHITE);
}
