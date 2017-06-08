/*
** game2.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Feb 25 11:22:37 2016 Robin Partouche
** Last update Sun Mar 20 22:15:19 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	while_refresh(int lock, t_game *tetris, int i, int j)
{
  if (lock == 1 && tetris->terran[i - 1][j] == 1 &&
      tetris->terran[i][j] > 1)
    end(tetris);
  else if (lock == 1 && tetris->terran[i][j] > 1)
    {
      tetris->terran[i][j] = tetris->terran[i][j] * -1;
      tetris->bool_bloc = 0;
    }
  else if (tetris->terran[i][j] > 1)
    {
      tetris->terran[i + 1][j] = tetris->terran[i][j];
      tetris->terran[i][j] = 0;
    }
}

void	create_bloc_next(t_game *tetris)
{
  if (tetris->info.next == 0)
    {
      print_sup_next_tetro(tetris, 0, 0);
      print_next_tetro(tetris, tetris->tetro[tetris->next_id - 2].i_t
      , tetris->tetro[tetris->next_id - 2].j_t,
      tetris->tetro[tetris->next_id - 2].color);
    }
  tetris->bool_bloc = 1;
}
