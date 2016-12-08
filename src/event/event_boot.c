/*
** event_boot.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue Jan 26 02:10:46 2016 Jamy Bailly
** Last update Wed Jan 27 08:24:59 2016 David Zeng
*/

#include "tekpaint.h"

void	event_boot(t_tek *tekpaint)
{
  int	i;

  i = 0;
  tekpaint->mouse.mouse_pos = (t_bunny_position *)bunny_get_mouse_position();
  while (i <= NB_EVENT)
    {
      if (tekpaint->mouse.mouse_pos->x >= tekpaint->mouse.zone[i][0].x &&
	  tekpaint->mouse.mouse_pos->x <= tekpaint->mouse.zone[i][1].x &&
	  tekpaint->mouse.mouse_pos->y >= tekpaint->mouse.zone[i][0].y &&
	  tekpaint->mouse.mouse_pos->y <= tekpaint->mouse.zone[i][1].y)
	{
	  tekpaint->mouse.func_event[i](tekpaint, &tekpaint->mouse);
	  return ;
	}
      else
	{
	  i++;
	}
    }
}
