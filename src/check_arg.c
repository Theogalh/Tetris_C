/*
** check_arg.c for check_arg in /home/thomas/git/tetra
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sun Mar  6 22:41:36 2016 thomas
** Last update Sun Mar 20 16:34:37 2016 Robin Partouche
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "info.h"
#include "game.h"
#include "my.h"

int	check_tiret(int argc, char **argv, char *binary_name)
{
  int	j;

  j = 1;
  if (argv[1][0] != '-')
    help(binary_name);
  while (j != argc)
    {
      if (argv[j][2] == 'h')
	help(binary_name);
      j = j + 1;
    }
  return (1);
}

void	check_map(t_info *info, t_game *tetris)
{
  if (info->line + 4 > LINES || LINES < 24 || LINES < tetris->long_max + 2
      || info->line <= 5)
    {
      my_putstr("Micheltris need more lines for running\n");
      exit(-1);
    }
  else if (((info->col + 2) * 2) + 34
	   + ((tetris->larg_max + 2) * 2) > COLS || info->col <= 5)
    {
      my_putstr("Micheltris need more cols for running\n");
      exit(-1);
    }
}
