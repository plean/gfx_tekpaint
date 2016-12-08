/*
** tekline.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Thu Jan 14 22:53:36 2016 Jamy Bailly
** Last update Wed Jan 27 08:24:44 2016 David Zeng
*/

#include "tekpaint.h"

static int	my_abs(int x)
{
  return (((x > 0) ? x : -x));
}

static void	init_line_box(t_bunny_position *pos,
			      t_line_box *box)
{
  box->dx = my_abs(pos[1].x - pos[0].x);
  box->dy = my_abs(pos[1].y - pos[0].y);
  box->pos.x = pos[0].x;
  box->pos.y = pos[0].y;
  box->sx = box->pos.x < pos[1].x ? 1 : -1;
  box->sy = box->pos.y < pos[1].y ? 1 : -1;
  box->err = (box->dx > box->dy ? box->dx : -(box->dy)) / 2;
  return ;
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color)
{
  t_line_box		*box;

  if ((box = bunny_malloc(sizeof(t_line_box))) == NULL)
    return ;
  init_line_box(pos, box);
  while (box->pos.x != pos[1].x || box->pos.y != pos[1].y)
    {
      tekpixel(pix, &box->pos, color);
      box->tmp = box->err;
      if (box->tmp > - (box->dx))
	{
	  box->err = box->err - box->dy;
	  box->pos.x = box->pos.x + box->sx;
	}
      if (box->tmp < box->dy)
	{
	  box->err = box->err + box->dx;
	  box->pos.y = box->pos.y + box->sy;
	}
    }
  bunny_free(box);
  return ;
}
