/*
** event_newfile.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue Jan 26 21:19:50 2016 Jamy Bailly
** Last update Wed Jan 27 08:12:11 2016 David Zeng
*/

#include "tekpaint.h"

int	event_newfile(void *tp, t_event_mouse *action)
{
  t_tek	*tekpaint;

  tekpaint = tp;
  if (action)
    set_background(tekpaint->img, set_color(255, 255, 255, 0));
  return (0);
}
