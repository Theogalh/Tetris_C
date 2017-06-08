/*
** init2.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Mar 17 20:04:50 2016 Robin Partouche
** Last update Sat Mar 19 16:57:36 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <ncurses/curses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void		init_ncurses(t_game *tetris)
{
  mode_convert(1);
  initscr();
  noecho();
  curs_set(0);
  mode_convert(0);
  tetris->level = tetris->info.level;
  print_logo(tetris);
  print_score_table();
}
