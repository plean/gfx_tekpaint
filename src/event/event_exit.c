/*
** event_exit.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Mon Jan 25 21:04:25 2016 Jamy Bailly
** Last update Wed Jan 27 03:28:18 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "my.h"

int	event_exit(void *tp, t_event_mouse *action)
{
  t_tek	*tekpaint;

  tekpaint = tp;
  if (tekpaint && action)
    action->event_response = EXIT_ON_SUCCESS;
  return (0);
}
