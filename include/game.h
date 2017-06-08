/*
** game.h for  in /home/partou_a/rendu/PSU_2015_tetris/include
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Feb 23 10:35:30 2016 Robin Partouche
** Last update Sun Mar 20 22:09:44 2016 Robin Partouche
*/

#ifndef GAME_H_
# define GAME_H_

# include <time.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct	s_tetro_door
{
  int		i;
  int		j;
  int		f;
  int		door;
}		t_tetro_door;

typedef struct  s_coord
{
  int		i;
  int		j;
}               t_coord;

typedef struct	s_pos
{
  int		x;
  int		y;
  int		id_bloc;
  int		line;
}		t_pos;

typedef struct  s_tetro
{
  char		*name;
  int		i_t;
  int		j_t;
  char		**img;
  int		color;
  t_pos		center;
  int		error;
  int		lock;
}		t_tetro;

typedef struct  s_game
{
  int		down_time;
  long		score;
  long		hscore;
  int		lines_down;
  int		level;
  long		time;
  unsigned long	stock_time;
  long		mtime;
  long		pause_time;
  t_info	info;
  t_tetro	*tetro;
  int		**terran;
  int		color;
  int		id_bloc;
  int		bool_bloc;
  int		rand_tetro;
  t_pos		center;
  int		line_to_level;
  int		arg;
  int		larg_max;
  int		long_max;
  int		next_id;
}               t_game;

void	print_score_table();
void	print_logo(t_game *tetris);
void	init_ncurses(t_game *game);
void	refresh_score(t_game *tetris);
void	init_base(t_game *tetris);
void	set_time(t_game *tetris);
void	init_colored();
void	color_letter(t_game *tetris);
void	color_off(t_game *tetris);
void	init_terran(t_game *tetris);
void	*init_map(int rows, int cols);
void	init_tetro(t_game *tetris);
void	move_side(t_game *tetris, char *input);
void	while_refresh(int lock, t_game *tetris, int i, int j);
void	end(t_game *tetris);

int	**my_double_str_int_dup(int **str, int col, int line);
void	my_put_t_int(int **str, t_game *tetris);
void	my_put2int(int **str);
void	validate_refresh(t_game *tetris, int lock);
void	create_bloc(t_game *tetris);
int	refresh_turn(t_game *tetris);
void	value_to_terran(t_game *tetris);
int	*my_str_int_dup(int *str, int length);
void	print_color(int color, int i, int j);
int	**prepare_terran(t_game *tetris, int **terran);

void	print_sup_next_tetro(t_game *tetris, int i, int j);
void	print_next_tetro(t_game *tetris, int i_t, int j_t, int color);
int	**move_up(int **tmp_terran, t_info info, t_pos center, int **terran);
void	pause_game(t_game *tetris, char* input);
int	**move_down(int **terran, int id_bloc, int col, int line);
void	get_points(t_game *tetris);

int	rotate_nord_ouest(int **tmp_terran, t_coord crd,
			  t_pos center, int **terran);
int	*my_str_int_dup(int *str, int length);
int	my_str_comparate(char *str, char *str2);
void	verif_dir(char *name);
void	range_tetro(t_game *tetris, int arg);

void	keep_tetro(t_game *tetris, DIR *fd_dir);

void	keep_tetro_end(t_game *tetris, struct dirent *buffer,
		       DIR *fd_dir, int arg);
void	keep_tetro_mid(int *arg, char *file, int fd);

void	get_tetro(t_game *tetris);
int	my_str_found(char *str, char *str2);
void	check_map(t_info *info, t_game *tetris);
char	*my_tetro_name(char *str);
void	tetro_while(t_tetro_door *tdoor, char *file, char **map);
int	get_tetro_info(t_game *tetris, char *file, int arg, int i);
int	verif_map(char **map, int line, int col, int door);
void	lock_tetro(t_game *tetris, char **map, int door, int arg);
void	debug(t_info *info, t_game *tetris);
void	tritetro(t_game *tetris, int max);
void	xexit(int a);
void	my_put2str(char **str);
void	init_high_score(t_game *tetris);
void	refresh_hscore(t_game *tetris);
void	my_putfd(char c, int fd);
int	length_buff(int fd);
void	create_bloc_next(t_game *tetris);

#endif /* !GAME_H_ */
