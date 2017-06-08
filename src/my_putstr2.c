/*
** my_putstr2.c for my_putstr2 in /home/theogalh/git/tetra
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Thu Mar 17 17:25:53 2016 Thomas Bouillon
** Last update Thu Mar 17 19:15:09 2016 Robin Partouche
*/

#include <unistd.h>

void	my_putstr2(char *s)
{
  int	i;

  i = 0;
  while (s[i] != 0)
    {
      write(2, &s[i], 1);
      i = i + 1;
    }
}
