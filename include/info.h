/*
** info.h for  in /home/partou_a/rendu/PSU_2015_tetris/include
**
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
**
** Started on  Tue Feb 23 10:35:43 2016 Robin Partouche
** Last update Sun Mar 20 16:43:49 2016 Robin Partouche
*/

#ifndef INFO_H_
# define INFO_H_

typedef struct	s_info
{
  int		col;
  int		line;
  int		next;
  int		level;
  int		debug;
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
  char		*map;
  int		ymax;
  int		xmax;
  char		*binary_name;
}		t_info;

int	check_tetri(char *buffer);
void	help(char *binary_name);
void	init_info(t_info *info, char *binary_name);
int	get_arg1(char *arg, char *cmp, int u, int size);
char	*get_arg2(char *arg, char *cmp, int u, int size);
int	check_h(int h, int j, char *argv, char *binary_name);
void	parsing1(int argc, char **argv, t_info *info, int j);
void	parsing2(int argc, char **argv, t_info *info, int j);
void	parsing3(char **argv, t_info *info, int j);
int	parsing4(t_info *info, char **argv, int h, int j);
char	*get_env(char **env, char *word);
int	setup_env(char **env, t_info *info);
int	mode_convert(int i);
int	check_tiret(int argc, char **argv, char *binary_name);
void	pauseandquit(t_info *info, char *term);
void	updownkey(t_info *info, char *term);
void	leftrightkey(t_info *info, char *term);
void	keybind(t_info *info, char *term);
void	check_level(t_info *info, int argc, char **argv);
void	takemap(t_info *info);
void	my_putstr2(char* str);
void	my_putkey(char *key);
int	verif_arg2(int *i, int size, char *arg, char *cmp);

#endif /* !INFO_H_ */
