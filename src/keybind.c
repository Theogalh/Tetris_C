/*
** keybind.c for keybind in /home/thomas/git/tetra
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Mar  7 15:07:53 2016 thomas
** Last update Sat Mar 19 00:39:54 2016 Robin Partouche
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "info.h"
#include "my.h"

void	pauseandquit(t_info *info, char *term)
{
  int	ret;

  if (setupterm(term, 1, &ret) != OK)
    exit(1);
  if (info->quit == NULL)
    info->quit = "q";
  if (info->pause == NULL)
    info->pause = " ";
}

void	updownkey(t_info *info, char *term)
{
  int	ret;

  if (setupterm(term, 1, &ret) != OK)
    exit(1);
  if (info->turn == NULL)
    info->turn = tigetstr("kcuu1");
  if (info->drop == NULL)
    info->drop = tigetstr("kcud1");
  if (info->turn == NULL || info->drop == NULL)
    {
      my_putstr("Votre term n'est pas compatible.\n");
      exit(-1);
    }
}

void	leftrightkey(t_info *info, char *term)
{
  int	ret;

  if (setupterm(term, 1, &ret) != OK)
    exit(1);
  if (info->left == NULL)
    info->left = tigetstr("kcub1");
  if (info->left == NULL)
    {
      my_putstr("Votre term n'est pas compatible.\n");
      exit(-1);
    }
  if (info->right == NULL)
    info->right = tigetstr("kcuf1");
  if (info->right == NULL)
    {
      my_putstr("Votre term n'est pas compatible.\n");
      exit(-1);
    }
}

void	keybind(t_info *info, char *term)
{
  char	*smkx;
  int	ret;

  if (setupterm(term, 1, &ret) != OK)
    exit(1);
  smkx = NULL;
  smkx = tigetstr("smkx");
  if (smkx == 0)
    exit(-1);
  my_putstr2(smkx);
  leftrightkey(info, term);
  updownkey(info, term);
  pauseandquit(info, term);
}
