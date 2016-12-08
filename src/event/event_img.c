/*
** event_img.c for event img in /home/zeng_d/rendu/Info/gfx_tekpaint
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 27 05:06:56 2016 David Zeng
** Last update Sat Jan 30 15:08:46 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "tools.h"

void			my_do_event_img(t_tek *tekpaint, t_event_mouse *action)
{
  t_tek			*tp;
  t_bunny_position	pos;

  tp = (t_tek *)tekpaint;
  pos.x = action->mouse_pos->x - 400;
  pos.y = action->mouse_pos->y - 84;
  if (tp->bool_data.line == 1 && (tp->bool_data.line = 2))
    {
      tp->bool_data.pos[0].x = pos.x;
      tp->bool_data.pos[0].y = pos.y;
    }
  else
    {
      tp->bool_data.pos[1].x = pos.x;
      tp->bool_data.pos[1].y = pos.y;
      tekpinceaux_line(tp->img, tp->bool_data.pos,
		       tp->bool_data.color, tp->bool_data.size);
      tp->bool_data.line = 1;
    }
}

int			event_img(void *tekpaint, t_event_mouse *action)
{
  t_tek			*tp;
  t_bunny_position	pos;

  tp = (t_tek *)tekpaint;
  pos.x = action->mouse_pos->x - 400;
  pos.y = action->mouse_pos->y - 84;
  if (tp->bool_data.circle)
    tekpinceaux_rond(tp->img, &pos,
		     tp->bool_data.color, tp->bool_data.size);
  else if (tp->bool_data.line && tp->press == 1)
    {
      my_do_event_img(tp, action);
      tp->press = 2;
    }
  else if (tp->bool_data.square)
    tekpinceaux_carre(tp->img, &pos,
		      tp->bool_data.color, tp->bool_data.size);
  else if (tp->bool_data.bucket)
    tekbucket(tp->img, &pos,
	      my_get_color(tp->img, pos.x, pos.y),
	      tp->bool_data.color);
  return (0);
}
