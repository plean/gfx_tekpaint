/*
** init_event_mouse.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Mon Jan 25 23:33:30 2016 Jamy Bailly
** Last update Wed Jan 27 06:22:04 2016 David Zeng
*/

#include "tekpaint.h"
#include "tools.h"

t_bunny_position	*create_frame(t_bunny_position *pos,
				      t_bunny_pixelarray *img)
{
  t_bunny_position	*frame;

  if ((frame = bunny_malloc(sizeof(t_bunny_position) * 2)) != NULL)
    {
      frame[0].x = pos->x;
      frame[0].y = pos->y;
      frame[1].x = pos->x + img->clipable.clip_width;
      frame[1].y = pos->y + img->clipable.clip_height;
    }
  return (frame);
}

static int	check_event_is_set(t_bunny_position **zone)
{
  int		i;

  i = 0;
  while (i != NB_EVENT)
    {
      if (zone[i] != NULL)
	i++;
      else
	{
	  return (-1);
	}
    }
  return (1);
}

int			create_event_mouse(t_tek *tekpaint)
{
  t_bunny_position	img_pos;

  img_pos.x = 400;
  img_pos.y = 64;
  tekpaint->mouse.event_response = GO_ON;
  init_event_palette(tekpaint);
  init_event_shape(tekpaint);
  init_event_tool(tekpaint);
  init_event_thickness(tekpaint);
  init_event_trans(tekpaint);
  init_event_toolbar(tekpaint);
  tekpaint->mouse.zone[15] = create_frame(&img_pos, tekpaint->img);
  tekpaint->mouse.func_event[15] = &event_img;
  return (check_event_is_set(tekpaint->mouse.zone));
}
