/*
** mouse.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Jan 16 23:01:41 2016 Jamy Bailly
** Last update Sat Jan 30 16:26:13 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "my.h"

void				print_mouse_position()
{
  const t_bunny_position	*mouse_pos;

  mouse_pos = bunny_get_mouse_position();
  my_putstr("Mouse position : X --> ");
  my_putnbr(mouse_pos->x);
  my_putstr(" Y --> ");
  my_putnbr(mouse_pos->y);
  my_putstr("\n");
}

t_bunny_response	mouse_click(t_bunny_event_state state,
				    t_bunny_mousebutton button,
				    void *data)
{
  t_tek			*tekpaint;

  tekpaint = data;
  if (state == GO_DOWN && button == BMB_LEFT)
    tekpaint->press = 1;
  else if (state == GO_UP && button == BMB_LEFT)
    tekpaint->press = 0;
  return (tekpaint->mouse.event_response);
}
