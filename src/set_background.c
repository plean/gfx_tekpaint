/*
** set_background.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Thu Jan 14 22:46:52 2016 Jamy Bailly
** Last update Fri Jan 15 23:02:47 2016 Jamy Bailly
*/

#include "tekpaint.h"

void		set_background(t_bunny_pixelarray *pix, int color)
{
  int		*pixels;
  unsigned int	length;
  unsigned int	i;

  i = 0;
  length = pix->clipable.clip_width * pix->clipable.clip_height;
  pixels = (int *) pix->pixels;
  while (i < length)
    {
      pixels[i] = color;
      i++;
    }
  return ;
}
