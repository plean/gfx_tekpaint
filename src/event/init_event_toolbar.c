/*
** init_event_toolbar.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Jan 27 04:29:55 2016 Jamy Bailly
** Last update Wed Jan 27 23:50:48 2016 Jean PLANCHER
*/

#include "tekpaint.h"

void		init_event_toolbar(t_tek *tekpaint)
{
  t_button	elem;

  elem = tekpaint->toolbar.buttons_toolbar.newfile;
  tekpaint->mouse.zone[11] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[11] = &event_newfile;
  elem = tekpaint->toolbar.buttons_toolbar.folder;
  tekpaint->mouse.zone[12] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[12] = &event_folder;
  elem = tekpaint->toolbar.buttons_toolbar.save;
  tekpaint->mouse.zone[13] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[13] = &event_save;
  elem = tekpaint->toolbar.buttons_toolbar.cancel;
  tekpaint->mouse.zone[14] = create_frame(&elem.button_pos, elem.button);
  tekpaint->mouse.func_event[14] = &event_exit;
}
