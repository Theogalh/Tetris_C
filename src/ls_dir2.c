/*
** ls_dir2.c for  in /home/partou_a/rendu/PSU_2015_tetris/src
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Mar 18 18:49:40 2016 Robin Partouche
** Last update Sun Mar 20 22:01:07 2016 Robin Partouche
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

char	*fs_read(int fd, int length)
{
  char	*buffer;

  if ((buffer = malloc(sizeof(*buffer) * (length + 1))) == NULL)
    exit(1);
  if ((length = read(fd, buffer, length)) == -1)
    {
      my_putstr("Error: Impossible to read the file.\n");
      exit(1);
    }
  buffer[length] = '\0';
  return (buffer);
}

int	fs_create(char *filepath)
{
  int	fd;

  if ((fd = open(filepath, O_CREAT | O_WRONLY, 0600)) == -1)
    {
      my_putstr("Error: Impossible to create file.\n");
      exit(1);
    }
  else
    return (fd);
}
