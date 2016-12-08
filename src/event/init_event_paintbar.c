/*
** init_event_paintbar.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Wed Jan 27 02:50:06 2016 Jamy Bailly
** Last update Wed Jan 27 05:44:14 2016 Jamy Bailly
*/

#include "tekpaint.h"

void		init_event_palette(t_tek *tekpaint)
{
  t_button	elem;

  elem = tekpaint->paintbar.buttons_paintbar.pcolors;
  tekpaint->mouse.zone[0] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[0] = &event_palette;
}

void		init_event_shape(t_tek *tekpaint)
{
  t_button	elem;

  elem = tekpaint->paintbar.buttons_paintbar.square;
  tekpaint->mouse.zone[1] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[1] = &event_square;
  elem = tekpaint->paintbar.buttons_paintbar.circle;
  tekpaint->mouse.zone[2] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[2] = &event_circle;
  elem = tekpaint->paintbar.buttons_paintbar.line;
  tekpaint->mouse.zone[3] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[3] = &event_line;
}

void		init_event_tool(t_tek *tekpaint)
{
  t_button	elem;

  elem = tekpaint->paintbar.buttons_paintbar.eraser;
  tekpaint->mouse.zone[4] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[4] = &event_eraser;
  elem = tekpaint->paintbar.buttons_paintbar.brush;
  tekpaint->mouse.zone[5] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[5] = &event_brush;
}

void		init_event_thickness(t_tek *tekpaint)
{
  t_button	elem;

  elem = tekpaint->paintbar.buttons_paintbar.minus;
  tekpaint->mouse.zone[6] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[6] = &event_minus;
  elem = tekpaint->paintbar.buttons_paintbar.more;
  tekpaint->mouse.zone[7] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[7] = &event_more;
}

void		init_event_trans(t_tek *tekpaint)
{
  t_button	elem;

  elem = tekpaint->paintbar.buttons_paintbar.tsquare;
  tekpaint->mouse.zone[8] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[8] = &event_blackwhite;
  elem = tekpaint->paintbar.buttons_paintbar.bucket;
  tekpaint->mouse.zone[9] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[9] = &event_bucket;
  elem = tekpaint->paintbar.buttons_paintbar.nsquare;
  tekpaint->mouse.zone[10] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[10] = &event_reverse;
}
