/*
** check_tetri.c for check_tetri in /home/thomas/git/tetra
**
** Made by thomas
** Login   <thomas@epitech.net>
**
** Started on  Sun Mar  6 19:41:26 2016 thomas
** Last update Sun Mar  6 21:18:15 2016 thomas
*/

int	check_tetri(char *buffer)
{
  int	i;
  int	h;

  i = 0;
  h = 0;
  while (buffer[i] != '\n')
    {
      if (buffer[i] >= '0' && buffer[i] <= '9')
	i = i + 1;
      else if (buffer[i] == ' ' && h < 2)
	{
	  h = h + 1;
	  i = i + 1;
	}
      else
	return (-1);
    }
  while (buffer[i] != 0)
    {
      if (buffer[i] == '*' || buffer[i] == ' ' || buffer[i] == '\n')
	i = i + 1;
      else
	return (-1);
    }
  return (1);
}
