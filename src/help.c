/*
** help.c for help in /home/theogalh/git/tetra
**
** Made by Thomas Bouillon
** Login   <theogalh@epitech.net>
**
** Started on  Tue Feb 23 11:12:09 2016 Thomas Bouillon
** Last update Sat Mar 19 19:03:19 2016 Robin Partouche
*/

#include <stdlib.h>
#include "my.h"

void	help(char *binary_name)
{
  my_putstr("Usage: ");
  my_putstr(binary_name);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help                 Display this help\n");
  my_putstr("  -l --level={num}       Start Tetris at level num\n");
  my_putstr("  -kl --key-left={K}     Move tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}    Move tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}     Turn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}     Set default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}     Quit program when press key K\n");
  my_putstr(
  "  -kp --key-pause={k}    Pause and restart game when press key K");
  my_putchar('\n');
  my_putstr("  --map-size={row, col}  Set game size at row, col\n");
  my_putstr("  -w --without-next      Hide next tetrimino\n");
  my_putstr("  -d --debug             Debug mode\n");
  exit(-1);
}
