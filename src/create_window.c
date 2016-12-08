/*
** create_window.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Thu Jan 14 22:45:17 2016 Jamy Bailly
** Last update Tue Jan 26 16:32:03 2016 Jamy Bailly
*/

#include "tekpaint.h"

int			create_window(t_data_win *win)
{
  t_bunny_window_style	style;
  int			x;
  int			y;

  win->x = WIN_WIDTH;
  win->y = WIN_HEIGHT;
  x = win->x;
  y = win->y;
  style = TITLEBAR | CLOSE_BUTTON;
  win->window = bunny_start_style(x, y, style, "TekPaint");
  return (0);
}
