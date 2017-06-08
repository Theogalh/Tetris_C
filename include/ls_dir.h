/*
** ls_dir.h for  in /home/partou_a/rendu/PSU_2015_tetris
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Fri Mar 18 19:13:21 2016 Robin Partouche
** Last update Sun Mar 20 22:02:41 2016 Robin Partouche
*/

#ifndef LS_DIR_H_
# define LS_DIR_H_

# include <sys/types.h>
# include <sys/stat.h>

DIR             *fs_open_dir(char *filepath);
int		fs_open(char *filepath);
void		fs_close_dir(DIR *filepath);
int		fs_close(int fd);

struct dirent	*fs_read_dir(DIR *fd);
char		*fs_read(int fd, int length);
int		fs_create(char *filepath);

#endif /* !LS_DIR_H_ */
