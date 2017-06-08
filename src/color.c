/*
** color.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Feb 23 14:23:50 2016 Robin Partouche
** Last update Fri Mar 18 21:37:33 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	color_letter(t_game *tetris)
{
  if (tetris->color == 7)
    tetris->color = 1;
  else
    tetris->color = tetris->color + 1;
  attron(COLOR_PAIR(tetris->color));
}

void	color_off(t_game *tetris)
{
  attroff(COLOR_PAIR(tetris->color));
}

void	print_color(int color, int i, int j)
{
  attron(COLOR_PAIR(color + 7));
  mvprintw(i + 1, j + 30, " ");
  attroff(COLOR_PAIR(color + 7));
}
