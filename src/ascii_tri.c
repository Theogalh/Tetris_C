/*
** ascii_tri.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sat Mar 19 17:22:25 2016 Robin Partouche
** Last update Sat Mar 19 19:39:58 2016 Robin Partouche
*/

#include <stdlib.h>
#include "info.h"
#include "game.h"
#include "my.h"

int		fakestrcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i] != 0)
    {
      if (s1[i] == s2[i])
	i = i + 1;
      else
	return (s1[i] - s2[i]);
    }
  return (s1[i] - s2[i]);
}

void	tritetro(t_game *tetris, int max)
{
  int		i;
  int		test;
  t_tetro	tmp;

  i = 0;
  while (i + 1 != max)
    {
      test = fakestrcmp(tetris->tetro[i].name, tetris->tetro[i + 1].name);
      if (test > 0)
	{
	  tmp = tetris->tetro[i];
	  tetris->tetro[i] = tetris->tetro[i + 1];
	  tetris->tetro[i + 1] = tmp;
	  i = 0;
	}
      else
	i = i + 1;
    }
}
