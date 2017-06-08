/*
** parsing.c for parsing in /home/thomas/git/tetra/include
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sun Mar  6 23:20:36 2016 thomas
** Last update Sun Mar 20 16:41:20 2016 Robin Partouche
*/

#include <stdio.h>
#include <stdlib.h>
#include "info.h"
#include "my.h"

int	get_arg1(char *arg, char *cmp, int u, int size)
{
  int	i;

  i = 0;
  while (i != size)
    {
      if (arg[i] == cmp[i])
	i = i + 1;
      else
	return (0);
    }
  if (u == 1)
    {
      if (arg[i] != 0)
	return (1);
      else
	return (2);
    }
  return (1);
}

char	*get_arg2(char *arg, char *cmp, int u, int size)
{
  int	i;
  int	h;
  char	*tmp;

  i = 0;
  h = 0;
  if ((verif_arg2(&i, size, arg, cmp)) == 0)
    return (NULL);
  if (u == 1)
    {
      if ((tmp = malloc(sizeof(char) * (my_strlen(arg)))) == NULL)
	exit(-1);
      while (arg[i] != 0)
	{
	  tmp[h] = arg[i];
	  i = i + 1;
	  h = h + 1;
	}
      tmp[h] = 0;
      return (tmp);
    }
  return (NULL);
}

int	check_h(int h, int j, char *argv, char *binary_name)
{
  if (argv[0] != '-')
    {
      h = h + 1;
      j = j + 1;
    }
  else
    j = 0;
  if (h != 1 || j > 1)
    help(binary_name);
  return (j);
}

void	parsing1(int argc, char **argv, t_info *info, int j)
{
  int	h;
  int	i;

  i = 0;
  while (j != argc)
    {
      h = 0;
      h = h + get_arg1(argv[j], "--help", 0, 6);
      h = h + get_arg1(argv[j], "-l", 1, 3);
      h = h + get_arg1(argv[j], "--level=", 1, 8);
      h = h + get_arg1(argv[j], "-w", 0, 2);
      if (info->next == 0)
	info->next = get_arg1(argv[j], "-w", 0, 2);
      h = h + get_arg1(argv[j], "-kl", 1, 4);
      h = h + get_arg1(argv[j], "-kr", 1, 4);
      h = h + get_arg1(argv[j], "-kt", 1, 4);
      h = h + get_arg1(argv[j], "-kd", 1, 4);
      h = h + get_arg1(argv[j], "-kp", 1, 4);
      h = h + get_arg1(argv[j], "-kq", 1, 4);
      h = parsing4(info, argv, h, j);
      i = check_h(h, i, argv[j], info->binary_name);
      j = j + 1;
    }
}

void	parsing2(int argc, char **argv, t_info *info, int j)
{
  while (j != argc)
    {
      if (info->left == NULL)
	info->left = get_arg2(argv[j], "--key-left=", 1, 11);
      if (info->right == NULL)
	info->right = get_arg2(argv[j], "--key-right=", 1, 12);
      if (info->turn == NULL)
	info->turn = get_arg2(argv[j], "--key-turn=", 1, 11);
      if (info->drop == NULL)
	info->drop = get_arg2(argv[j], "--key-drop=", 1, 11);
      if (info->quit == NULL)
	info->quit = get_arg2(argv[j], "--key-quit=", 1, 11);
      if (info->pause == NULL)
	info->pause = get_arg2(argv[j], "--key-pause=", 1, 12);
      if (info->map == NULL)
	info->map = get_arg2(argv[j], "--map-size=", 1, 11);
      parsing3(argv, info, j);
      j = j + 1;
    }
}
