/*
** tekpixel.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Thu Jan 14 22:52:15 2016 Jamy Bailly
** Last update Thu Jan 14 22:52:15 2016 Jamy Bailly
*/

#include "tekpaint.h"

void	tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int	*pixels;

  pixels = (int *) pix->pixels;
  pixels[pix->clipable.clip_width * pos->y + pos->x] = color->full;
  return ;
}
