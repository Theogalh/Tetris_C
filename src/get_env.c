/*
** get_env.c for get_env in /home/thomas/git/tetra
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Mon Mar  7 14:46:08 2016 thomas
** Last update Thu Mar 17 19:29:48 2016 Robin Partouche
*/

#include <stdlib.h>

char	*env_line(int i, int j, char **env)
{
  char	*line;
  int	h;

  h = 0;
  if ((line = malloc(sizeof(char *) * 180)) == NULL)
    exit(-1);
  while (env[i][j] != 0 && env[i][j] != '\n')
    {
      line[h] = env[i][j];
      h = h + 1;
      j = j + 1;
    }
  line[h] = 0;
  return (line);
}

char	*get_env(char **env, char *word)
{
  int	i;
  int	j;
  int	h;

  i = 0;
  h = 0;
  j = 0;
  while (env[i] != NULL)
    {
      while (word[h] == env[i][j])
	{
	  if (env[i][j + 1] == '=')
	    return (env_line(i, j + 2, env));
	  h = h + 1;
	  j = j + 1;
	}
      i = i + 1;
      j = 0;
      h = 0;
    }
  return (NULL);
}
