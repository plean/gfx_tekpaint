/*
** paintbar.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue Jan 26 16:32:41 2016 Jamy Bailly
** Last update Sat Jan 30 14:44:55 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "paintbar.h"

int	create_paintbar(t_paintbar *paintbar)
{
  paintbar->background = bunny_new_pixelarray(400, IMG_HEIGHT);
  set_background(paintbar->background, set_color(0, 0, 0, 0));
  return (load_buttons_paintbar(&paintbar->buttons_paintbar));
}

void			paintbar_blit(t_paintbar *paintbar,
				      t_bunny_buffer *buffer)
{
  t_bunny_position	paintbar_pos;

  paintbar_pos.x = 0;
  paintbar_pos.y = 84;
  bunny_blit(buffer, &paintbar->background->clipable, &paintbar_pos);
  blit_buttons_paintbar(&paintbar->buttons_paintbar, buffer);
}

int			load_buttons_paintbar(t_buttons_paintbar *bts_paintbar)
{
  t_bunny_position      button_pos;
  int                   s;

  load_buttons_palette_paintbar(bts_paintbar, &button_pos, &s);
  load_buttons_shape_paintbar(bts_paintbar, &button_pos, &s);
  load_buttons_tool_paintbar(bts_paintbar, &button_pos, &s);
  load_buttons_thickness_paintbar(bts_paintbar, &button_pos, &s);
  load_buttons_trans_paintbar(bts_paintbar, &button_pos, &s);
  if (s < 0)
    return (-1);
  else
    return (0);
}

void    blit_buttons_paintbar(t_buttons_paintbar *b_pb,
			      t_bunny_buffer *buf)
{
  bunny_blit(buf, &b_pb->pcolors.button->clipable, &b_pb->pcolors.button_pos);
  bunny_blit(buf, &b_pb->square.button->clipable, &b_pb->square.button_pos);
  bunny_blit(buf, &b_pb->circle.button->clipable, &b_pb->circle.button_pos);
  bunny_blit(buf, &b_pb->line.button->clipable, &b_pb->line.button_pos);
  bunny_blit(buf, &b_pb->eraser.button->clipable, &b_pb->eraser.button_pos);
  bunny_blit(buf, &b_pb->brush.button->clipable, &b_pb->brush.button_pos);
  bunny_blit(buf, &b_pb->minus.button->clipable, &b_pb->minus.button_pos);
  bunny_blit(buf, &b_pb->more.button->clipable, &b_pb->more.button_pos);
  bunny_blit(buf, &b_pb->tsquare.button->clipable, &b_pb->tsquare.button_pos);
  bunny_blit(buf, &b_pb->bucket.button->clipable, &b_pb->bucket.button_pos);
  bunny_blit(buf, &b_pb->nsquare.button->clipable, &b_pb->nsquare.button_pos);
}
