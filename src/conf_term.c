/*
** conf_term.c for conf_term in /home/thomas/git/tetra
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Mar  7 09:10:25 2016 thomas
** Last update Sat Mar 19 00:28:53 2016 Robin Partouche
*/

#include <curses.h>
#include <term.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "info.h"

int		setup_env(char **env, t_info *info)
{
  char	*term;
  int	ret;

  if ((term = get_env(env, "TERM")) == NULL)
    exit(-1);
  if (setupterm(term, 1, &ret) == -1)
    exit(-1);
  keybind(info, term);
  return (0);
}

int		mode_convert(int i)
{
  static struct	termios old_conf;
  static struct	termios new_conf;

  if (i == 0)
    {
      ioctl(0, TCGETS, &new_conf);
      new_conf.c_lflag &= ~ECHO;
      new_conf.c_lflag &= ~ICANON;
      new_conf.c_cc[VMIN] = 0;
      new_conf.c_cc[VTIME] = 1;
      ioctl(0, TCSETS, &new_conf);
    }
  else if (i == 1)
    {
      ioctl(0, TCGETS, &old_conf);
    }
  else
    ioctl(0, TCSETS, &old_conf);
  return (0);
}

void	xexit(int a)
{
  mode_convert(2);
  exit(a);
}
