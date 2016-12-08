/*
** brush.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Jan 27 05:51:46 2016 Jamy Bailly
** Last update Sat Jan 30 16:31:56 2016 David Zeng
*/

#include "tekpaint.h"
#include "tools.h"

void		init_bool(t_bool *bool_data)
{
  bool_data->size = 20;
  bool_data->square = 0;
  bool_data->circle = 1;
  bool_data->line = 0;
  bool_data->eraser = 0;
  bool_data->brush = 0;
  bool_data->bucket = 0;
  bool_data->color = BLACK;
  bool_data->alpha = 33;
  bool_data->precision = 100;
}

int			event_palette(void *tekpaint, t_event_mouse *action)
{
  t_tek			*tp;
  t_color		col;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;

  tp = tekpaint;
  pos.x = 15;
  pos.y = 140;
  pix = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT);
  my_blit_pixel(pix, tp->palette, &pos);
  tp->bool_data.color = my_get_color(pix,
				      action->mouse_pos->x,
				      action->mouse_pos->y);
  col.full = tp->bool_data.color;
  col.argb[3] = tp->bool_data.alpha;
  tp->bool_data.color = col.full;
  bunny_delete_clipable(&pix->clipable);
  return (0);
}

int		event_bucket(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  if (tp->bool_data.eraser == 1)
    tp->bool_data.color = BLACK;
  tp->bool_data.square = 0;
  tp->bool_data.circle = 0;
  tp->bool_data.line = 0;
  tp->bool_data.eraser = 0;
  tp->bool_data.brush = 0;
  tp->bool_data.bucket = 1;
  return (0);
}

int		event_minus(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  if (tp->press == 1)
    {
      if (tp->bool_data.size - SHIFT_SIZE >= 2)
	tp->bool_data.size -= SHIFT_SIZE;
      else
	tp->bool_data.size = 2;
    }
  return (0);
}

int		event_more(void *tekpaint, t_event_mouse *action)
{
  t_tek		*tp;

  (void)action;
  tp = tekpaint;
  if (tp->press == 1)
    {
      if (tp->bool_data.size + SHIFT_SIZE <= 300)
	tp->bool_data.size += SHIFT_SIZE;
      else
	tp->bool_data.size = 300;
    }
  return (0);
}
