/*
** parsing2.c for parsing2 in /home/thomas/git/tetra
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Mar  7 10:40:47 2016 thomas
** Last update Sun Mar 20 16:32:18 2016 Robin Partouche
*/

#include <stdlib.h>
#include "info.h"
#include "my.h"

char	*take_arg(char **argv, char *arg, int j, char *binary_name)
{
  int	i;

  i = get_arg1(argv[j], arg, 0, my_strlen(arg));
  if (i == 1)
    {
      j = j + 1;
      if (argv[j][0] == '-')
	help(binary_name);
      else
	return (argv[j]);
    }
  else
    return (NULL);
  return (NULL);
}

void	parsing3(char **argv, t_info *info, int j)
{
  if (info->left == NULL)
    info->left = take_arg(argv, "-kl", j, info->binary_name);
  if (info->right == NULL)
    info->right = take_arg(argv, "-kr", j, info->binary_name);
  if (info->turn == NULL)
    info->turn = take_arg(argv, "-kt", j, info->binary_name);
  if (info->drop == NULL)
    info->drop = take_arg(argv, "-kd", j, info->binary_name);
  if (info->quit == NULL)
    info->quit = take_arg(argv, "-kq", j, info->binary_name);
  if (info->pause == NULL)
    info->pause = take_arg(argv, "-kp", j, info->binary_name);
}

int	parsing4(t_info *info, char **argv, int h, int j)
{
  h = h + get_arg1(argv[j], "--map-size=", 1, 11);
  h = h + get_arg1(argv[j], "--without-next", 0, 14);
  if (info->next == 0)
    info->next = get_arg1(argv[j], "--without-next", 0, 14);
  if (info->next == 0)
    info->next = get_arg1(argv[j], "-w", 0, 2);
  h = h + get_arg1(argv[j], "--debug", 0, 7);
  if (info->debug == 0)
    info->debug = get_arg1(argv[j], "--debug", 0, 7);
  h = h + get_arg1(argv[j], "-d", 0, 2);
  if (info->debug == 0)
    info->debug = get_arg1(argv[j], "-d", 0, 2);
  h = h + get_arg1(argv[j], "--key-left=", 1, 11);
  h = h + get_arg1(argv[j], "--key-right=", 1, 12);
  h = h + get_arg1(argv[j], "--key-turn=", 1, 11);
  h = h + get_arg1(argv[j], "--key-drop=", 1, 11);
  h = h + get_arg1(argv[j], "--key-quit=", 1, 11);
  h = h + get_arg1(argv[j], "--key-pause=", 1, 12);
  return (h);
}

void	setinfo(t_info *info, int h)
{
  int	row;
  int	col;
  int	i;
  char	*tmp;

  if ((tmp = malloc(sizeof(char) * (10))) == NULL)
    exit(-1);
  info->map[h] = 0;
  row = my_getnbr(info->map);
  i = 0;
  h = h + 1;
  while (info->map[h] != 0)
    {
      tmp[i] = info->map[h];
      i = i + 1;
      h = h + 1;
    }
  tmp[i] = 0;
  col = my_getnbr(tmp);
  free(tmp);
  info->line = row;
  info->col = col;
}

void	takemap(t_info *info)
{
  int	i;
  int	h;

  i = 0;
  h = 0;
  while (info->map[i] != 0)
    {
      if (info->map[i] == ',')
	{
	  h = i;
	  i = i + 1;
	}
      else if (info->map[i] >= '0' && info->map[i] <= '9')
	i = i + 1;
      else
	help(info->binary_name);
    }
  if (h < 1)
    help(info->binary_name);
  else
    setinfo(info, h);
}
