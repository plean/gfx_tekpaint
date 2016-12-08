/*
** event_trans.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Jan 27 02:38:00 2016 Jamy Bailly
** Last update Thu Jan 28 00:00:50 2016 Jean PLANCHER
*/

#include "tekpaint.h"
#include "tools.h"
#include "my.h"

int	event_blackwhite(void *tp, t_event_mouse *action)
{
  t_tek	*tekpaint;

  tekpaint = tp;
  if (action && tekpaint->press == 1)
    tekblackwhite(tekpaint->img);
  return (0);
}

int	event_reverse(void *tp, t_event_mouse *action)
{
  t_tek	*tekpaint;

  tekpaint = tp;
  if (action && tekpaint->press == 1)
    tekreverse(tekpaint->img);
  return (0);
}
