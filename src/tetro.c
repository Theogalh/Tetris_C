/*
** tetro.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Mar 20 16:29:24 2016 Robin Partouche
** Last update Sun Mar 20 21:16:34 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	lock_tetro(t_game *tetris, char **map, int door, int arg)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  tetris->tetro[arg].lock = 0;
  if (tetris->tetro[arg].i_t == tetris->tetro[arg].j_t)
    tetris->tetro[arg].lock = 1;
  while (map[i] != 0)
    {
      while (map[i][j] != 0)
	{
	  if (map[i][j] == ' ')
	    door = 1;
	  if (door == 1 && map[i][j] == '*')
	    tetris->tetro[arg].lock = 0;
	  j = j + 1;
	}
      door = 0;
      i = i + 1;
      j = 0;
    }
}

void	my_putkey(char *key)
{
  int	i;

  i = 0;
  while (key[i] != 0)
    {
      if (key[0] == ' ')
	my_putstr("(space)");
      else if (key[i] == 27)
	my_putstr("^E");
      else
	my_putchar(key[i]);
      i = i + 1;
    }
}

void	my_putfd(char c, int fd)
{
  write(fd, &c, 1);
}
