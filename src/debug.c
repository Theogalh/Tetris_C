/*
** debug.c for debug in /home/theogalh/git/tetra
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Tue Feb 23 14:34:00 2016 Thomas Bouillon
** Last update Sun Mar 20 16:36:19 2016 Robin Partouche
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "info.h"
#include "game.h"
#include "my.h"

void	range_tetro(t_game *tetris, int arg)
{
  int	i;
  int	j;

  i = 0;
  while (i != arg)
    {
      if (tetris->tetro[i].error == 1)
	{
	  if (i + 1 != arg)
	    {
	      j = i;
	      while (j != arg)
		{
		  tetris->tetro[j] = tetris->tetro[j + 1];
		  j = j + 1;
		}
	    }
	  tetris->arg = tetris->arg - 1;
	  arg = arg - 1;
	}
      else
	{
	  i = i + 1;
	}
    }
}

void	key(t_info *info)
{
  my_putstr("Key Left : ");
  my_putkey(info->left);
  my_putstr("\nKey Right : ");
  my_putkey(info->right);
  my_putstr("\nKey Turn : ");
  my_putkey(info->turn);
  my_putstr("\nKey Drop : ");
  my_putkey(info->drop);
  my_putstr("\nKey Quit : ");
  my_putkey(info->quit);
  my_putstr("\nKey Pause : ");
  my_putkey(info->pause);
  my_putchar('\n');
}

void	press_a_key()
{
  int	len;
  char	*input;

  if ((input = malloc(10 * sizeof(char*))) == NULL)
    xexit(1);
  my_putstr("Press a key to start Tetris\n");
  len = 0;
  mode_convert(1);
  mode_convert(0);
  while (len == 0)
    {
      len = read(0, input, 10);
      input[len] = 0;
    }
  mode_convert(2);
}

void	tetri_debug(t_game *tetris, int arg, int i)
{
  my_putstr("Tetriminos : ");
  my_put_nbr(arg);
  my_putchar('\n');
  while (i != arg)
    {
      my_putstr("Tetriminos : Name ");
      my_putstr(tetris->tetro[i].name);
      my_putstr(" : ");
      if (tetris->tetro[i].error == 1)
	my_putstr("Error\n");
      else
	{
	  my_putstr("Size ");
	  my_put_nbr(tetris->tetro[i].j_t);
	  my_putstr("*");
	  my_put_nbr(tetris->tetro[i].i_t);
	  my_putstr(" : Color ");
	  my_put_nbr(tetris->tetro[i].color);
	  my_putstr(" :\n");
	  my_put2str(tetris->tetro[i].img);
	}
      i = i + 1;
    }
}

void	debug(t_info *info, t_game *tetris)
{
  my_putstr("*** DEBUG MODE ***\n");
  key(info);
  my_putstr("Next : ");
  if (info->next == 0)
    my_putstr("Yes\n");
  else
    my_putstr("No\n");
  my_putstr("Level : ");
  my_put_nbr(info->level);
  my_putstr("\nSize : ");
  my_put_nbr(info->line);
  my_putchar('*');
  my_put_nbr(info->col);
  my_putchar('\n');
  tetri_debug(tetris, tetris->arg, 0);
  press_a_key();
}
