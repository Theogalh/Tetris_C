/*
** ls_dir.c for  in /home/partou_a/rendu/PSU_2015_my_ls
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Thu Nov 26 17:22:48 2015 Robin Partouche
** Last update Sun Mar 20 21:56:23 2016 Robin Partouche
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

int	fs_open(char *filepath)
{
  int	fd;

  if ((fd = open(filepath, O_RDWR)) == -1)
    {
      return (0);
    }
  else
    return (fd);
}

DIR	*fs_open_dir(char *filepath)
{
  DIR	*test;

  if ((test = opendir(filepath)) == NULL)
    {
      my_putstr("Error : Impossible to open directory.\n");
      exit(1);
    }
  else
    return (test);
}

void	fs_close_dir(DIR *filepath)
{
  if (closedir(filepath) == -1)
    {
      my_putstr("Error : Impossible to close directory.\n");
      exit(1);
    }
}

int	fs_close(int fd)
{
  if (close(fd) == -1)
    {
      my_putstr("Error: Impossible to close file.\n");
    }
  return (0);
}

struct dirent	*fs_read_dir(DIR *fd)
{
  struct dirent	*i;

  i = readdir(fd);
  return (i);
}

