/*
** tekblackwhite.c for  in /home/planch_j/rendu/Info/gfx_tekpaint/add_later/planch_j
** 
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
** 
** Started on  Tue Jan 26 18:55:32 2016 Jean PLANCHER
** Last update Wed Jan 27 03:19:56 2016 Jamy Bailly
*/

#include <lapin.h>
#include "tools.h"

void		tekblackwhite(t_bunny_pixelarray *pix)
{
  unsigned int	*pixels;
  t_color	t;
  int		i;
  int		k;

  i = -1;
  pixels = pix->pixels;
  while (++i < pix->clipable.clip_width * pix->clipable.clip_height)
    {
      t.full = my_get_color(pix, i % pix->clipable.clip_width,
			    i / pix->clipable.clip_width);
      k = (t.argb[0] + t.argb[1] + t.argb[2]) / 3;
      t.argb[0] = k;
      t.argb[1] = k;
      t.argb[2] = k;
      pixels[i] = t.full;
    }
}
