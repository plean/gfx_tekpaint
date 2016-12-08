/*
** tekpinceaux.c for  in /home/planch_j/rendu/Info/gfx_tekpaint/planch_j
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Mon Jan  4 15:44:02 2016 Jean PLANCHER
** Last update Fri Jan 29 14:32:59 2016 Jean PLANCHER
*/

#include <lapin.h>
#include <math.h>
#include "tekpaint.h"
#include "tools.h"

void			tekpinceaux_rond(t_bunny_pixelarray *pix,
					 t_bunny_position *pos,
					 unsigned int color,
					 int taille)
{
  t_bunny_position	pos2;
  t_color		t;
  int			radius;
  int			i;
  int			j;

  t.full = color;
  radius = taille / 2;
  i = -radius;
  while (i <= radius)
    {
      j = -radius;
      while (j <= radius)
	{
	  if (i * i + j * j < radius * radius &&
	      if_in_array(pix, pos->x + i, pos->y + j))
	    {
	      pos2.x = pos->x + i;
	      pos2.y = pos->y + j;
	      whallacmarrant(pix, &pos2, &t);
	    }
	  j++;
	}
      i++;
    }
}

void			tekpinceaux_carre(t_bunny_pixelarray *pix,
					  t_bunny_position *pos,
					  unsigned int color,
					  int taille)
{
  t_bunny_position	pos2;
  t_color		t;
  int			radius;
  int			i;
  int			j;

  t.full = color;
  radius = taille / 2;
  i = -radius;
  while (i <= radius)
    {
      j = -radius;
      while (j <= radius)
	{
	  if (if_in_array(pix, pos->x + i, pos->y + j))
	    {
	      pos2.x = pos->x + i;
	      pos2.y = pos->y + j;
	      whallacmarrant(pix, &pos2, &t);
	    }
	  j++;
	}
      i++;
    }
}

void			vertline(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color,
				 int taille)
{
  t_bunny_position	p;
  int			i;
  int			j;

  j = pos[0].y > pos[1].y;
  i = (pos[j].y < 0) * -pos[j].y;
  while (i < pos[!j].y - pos[j].y &&
	 i + pos[j].y < pix->clipable.buffer.height)
    {
      p.y = pos[j].y + i;
      p.x = pos[j].x + ((pos[!j].x - pos[j].x) * i) / (pos[!j].y - pos[j].y);
      tekpinceaux_rond(pix, &p, color->full, taille);
      i = i + 1;
    }
}

void			tekpinceaux_line(t_bunny_pixelarray *pix,
					 t_bunny_position *pos,
					 unsigned int t,
					 int taille)
{
  t_color		color;
  t_bunny_position	p;
  int			i;
  int			j;

  color.full = t;
  color.argb[3] = 0xFF;
  i = 0;
  if ((pos[1].y == pos[0].y) || (pos[1].x - pos[0].x) / (pos[1].y - pos[0].y))
    {
      j = pos[0].x > pos[1].x;
      i = (pos[j].x < 0) * -pos[j].x - 1;
      while (++i < pos[!j].x - pos[j].x &&
	     i + pos[j].x < pix->clipable.buffer.width)
	{
	  p.x = pos[j].x + i;
	  p.y = pos[j].y + ((pos[!j].y - pos[j].y) * i)
	    / (pos[!j].x - pos[j].x);
	  tekpinceaux_rond(pix, &p, color.full, taille);
	}
    }
  else
    vertline(pix, pos, &color, taille);
}
