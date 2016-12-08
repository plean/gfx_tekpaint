/*
** set_color.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Thu Jan 14 22:47:04 2016 Jamy Bailly
** Last update Thu Jan 14 22:47:13 2016 Jamy Bailly
*/

#include "tekpaint.h"

int		set_color(int r, int g, int b, int a)
{
  t_color	color;

  color.argb[0] = r;
  color.argb[1] = g;
  color.argb[2] = b;
  color.argb[3] = a;
  return (color.full);
}
