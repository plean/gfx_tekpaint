/*
** event_folder.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/event
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Jan 27 04:51:09 2016 Jamy Bailly
** Last update Wed Jan 27 23:48:01 2016 Jean PLANCHER
*/

#include "tekpaint.h"
#include "bmp.h"
#include "get_next_line.h"
#include "my.h"

int	event_folder(void *tp, t_event_mouse *action)
{
  t_tek	*tekpaint;
  char	*response;
  char	*path;

  tekpaint = tp;
  if (action && tekpaint)
    {
      my_putstr("Voulez-vous ouvrir un fichier .bmp(0) ou .ini(1) ? > ");
      response = get_next_line(0);
      my_putstr("Quel fichier voulez-vous ouvrir ? > ");
      path = get_next_line(0);
      if (my_getnbr(response) == 1)
	{
	  bunny_delete_clipable(&tekpaint->img->clipable);
	  tekpaint->img = my_load(path);
	}
      else
	{
	  bunny_delete_clipable(&tekpaint->img->clipable);
	  tekpaint->img = my_load_bmp(path);
	}
    }
  return (0);
}
