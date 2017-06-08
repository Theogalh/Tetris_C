/*
** main.c for  in /home/partou_a/rendu/PSU_2015_my_ls
** 
** Made by Robin Partouche
** Login   <partou_a@epitech.net>
** 
** Started on  Tue Nov 24 13:07:44 2015 Robin Partouche
** Last update Tue Mar 22 17:44:13 2016 Robin Partouche
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "mylist.h"
#include "info.h"
#include "game.h"

void	signal_int(int signal)
{
  if (signal == SIGINT)
    {
      endwin();
      xexit(0);
    }
}

void	while_time(t_game *tetris)
{
  if (tetris->down_time % 1 == 0)
    {
      print_score_table();
      print_logo(tetris);
      refresh_score(tetris);
    }
}

int	while_tetris(t_game tetris, int len)
{
  char	*input;

  if ((input = malloc(10 * sizeof(char*))) == NULL)
    xexit(1);
  input[0] = 0;
  while (my_str_comparate(tetris.info.quit, input) == 0)
    {
      tetris.time = time(NULL) + tetris.pause_time -
      tetris.stock_time - tetris.mtime * 60;
      pause_game(&tetris, input);
      move_side(&tetris, input);
      while_time(&tetris);
      create_bloc(&tetris);
      my_put_t_int(tetris.terran, &tetris);
      if (tetris.down_time <= 0)
	{
	  validate_refresh(&tetris, refresh_turn(&tetris));
	  tetris.down_time = 15000 - tetris.level * 500;
	}
      tetris.down_time = tetris.down_time - 1000;
      refresh();
      len = read(0, input, 10);
      input[len] = 0;
    }
  return (0);
}

int	init_the_game(t_game tetris)
{
  if (tetris.info.debug != 0)
    debug(&tetris.info, &tetris);
  range_tetro(&tetris, tetris.arg);
  init_ncurses(&tetris);
  srand(time(NULL));
  stdout = stderr;
  init_terran(&tetris);
  tetris.next_id = rand() % tetris.arg + 2;
  if (tetris.info.level == 0)
    tetris.level = 1;
  while_tetris(tetris, 0);
  endwin();
  xexit(1);
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_info	info;
  t_game	tetris;

  init_info(&info, argv[0]);
  tetris.info = info;
  init_base(&tetris);
  signal(SIGINT, signal_int);
  if (argc > 1)
    {
      check_tiret(argc, argv, argv[0]);
      parsing1(argc, argv, &info, 1);
      parsing2(argc, argv, &info, 1);
      check_level(&info, argc, argv);
      if (info.level == 0)
	info.level = 1;
      if (info.map != NULL)
	takemap(&info);
    }
  setup_env(env, &info);
  get_tetro(&tetris);
  check_map(&info, &tetris);
  tetris.info = info;
  return (init_the_game(tetris));
}
