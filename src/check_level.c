/*
** check_level.c for check_level in /home/theogalh/git/tetra
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Thu Mar 17 17:07:36 2016 Thomas Bouillon
** Last update Sun Mar 20 17:44:01 2016 Robin Partouche
*/

#include <stdlib.h>
#include "info.h"
#include "my.h"

int	check_nb(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  else if (str[i] == 0)
    return (-1);
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	return (-1);
    }
  return (0);
}

void	error_level(int level)
{
  if (level >= 31 || level <= 0)
    {
      my_putstr("Bad level\n");
      exit(1);
    }
}

int	check_level2(char *test, char *arg)
{
  int	i;

  i = get_arg1(test, "-l", 0, 2);
  if (i == 1)
    {
      if (arg == NULL)
	error_level(0);
      i = 0;
      while (arg[i] != 0)
	{
	  if (arg[i] <= '9' && arg[i] >= '0')
	    i = i + 1;
	  else
	    error_level(0);
	}
      i = my_getnbr(arg);
      error_level(i);
    }
  else
    return (0);
  return (i);
}

void	check_level(t_info *info, int argc, char **argv)
{
  int	j;
  char	*tmp;
  int	h;

  j = 1;
  while (j != argc)
    {
      if (info->level == 0 &&
          (tmp = get_arg2(argv[j], "--level=", 1, 8)) != NULL)
	{
	  if (tmp != NULL)
	    h = check_nb(tmp);
	  if (h == 0)
	    {
	      error_level(my_getnbr(tmp));
	      info->level = my_getnbr(tmp);
	    }
	  else
	    error_level(0);
	  free(tmp);
	}
      else if (info->level == 0)
	info->level = check_level2(argv[j], argv[j + 1]);
      j = j + 1;
    }
}
