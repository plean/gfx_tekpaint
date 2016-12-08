/*
** tekreverse.c for  in /home/planch_j/rendu/Info/gfx_tekpaint/add_later/planch_j
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Jan 26 14:45:21 2016 Jean PLANCHER
** Last update Thu Jan 28 15:11:10 2016 Jean PLANCHER
*/

#include <lapin.h>
#include "tools.h"

void		whallacmarrant(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color *t)
{
  unsigned int	*pixel;
  double	percent;
  t_color	c;

  percent = (double)t->argb[3] / 255.0;
  if (percent != 1)
    {
      c.full = my_get_color(pix, pos->x, pos->y);
      c.argb[2] = t->argb[2] * percent + c.argb[2] * (1 - percent);
      c.argb[1] = t->argb[1] * percent + c.argb[1] * (1 - percent);
      c.argb[0] = t->argb[0] * percent + c.argb[0] * (1 - percent);
    }
  else
    c.full = t->full;
  pixel = (unsigned int*)pix->pixels;
  if (pos->x < pix->clipable.clip_width &&
      pos->y < pix->clipable.clip_height)
    {
      pixel[pix->clipable.clip_width * pos->y + pos->x] = c.full;
    }
}

void		tekreverse(t_bunny_pixelarray *pix)
{
  unsigned int	*pixels;
  int		i;

  i = -1;
  pixels = pix->pixels;
  while (++i < pix->clipable.clip_width * pix->clipable.clip_height)
    pixels[i] = 0xFFFFFFFF - my_get_color(pix, i % pix->clipable.clip_width,
					  i / pix->clipable.clip_width);
}

int	if_in_array(t_bunny_pixelarray *pix, int x, int y)
{
  if (x < 0 || y < 0)
    return (0);
  if (x >= pix->clipable.clip_width || y >= pix->clipable.clip_width)
    return (0);
  return (1);
}

unsigned int		my_get_color(t_bunny_pixelarray *pix,
				     int x,
				     int y)
{
  t_bunny_position	pos;
  unsigned int		*pixel;

  if (x < 0 || y < 0 || x >= pix->clipable.clip_width ||
      y >= pix->clipable.clip_height)
    return (0);
  pos.x = x;
  pos.y = y;
  pixel = (unsigned int*)pix->pixels;
  return (pixel[pix->clipable.clip_width * pos.y + pos.x]);
}
