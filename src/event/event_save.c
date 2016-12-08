/*
** event_save.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Jan 27 04:54:24 2016 Jamy Bailly
** Last update Wed Jan 27 23:49:28 2016 Jean PLANCHER
*/

#include "tekpaint.h"
#include "get_next_line.h"
#include "bmp.h"
#include "my.h"

int	event_save(void *tp, t_event_mouse *action)
{
  t_tek	*tekpaint;
  char	*response;
  char	*path;

  tekpaint = tp;
  if (action && tekpaint)
    {
      my_putstr("Voulez-vous sauvegarder en .bmp(0) ou .ini(1) ? > ");
      response = get_next_line(0);
      my_putstr("Où sauvegarder le fichier ? > ");
      path = get_next_line(0);
      if (my_getnbr(response) == 1)
	my_save(tekpaint->img, path);
      else
	save_bmp(tekpaint->img, path);
    }
  return (0);
}
