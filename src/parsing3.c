/*
** parsing3.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Sun Mar 20 16:38:56 2016 Robin Partouche
** Last update Sun Mar 20 17:01:19 2016 Robin Partouche
*/

#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#include "my.h"

int	verif_arg2(int *i, int size, char *arg, char *cmp)
{
  while (*i != size)
    {
      if (arg[*i] == cmp[*i])
	*i = *i + 1;
      else
	return (0);
    }
  return (1);
}
