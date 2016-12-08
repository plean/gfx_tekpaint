/*
** destroy.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Jan 16 22:08:13 2016 Jamy Bailly
** Last update Wed Jan 27 08:03:45 2016 David Zeng
*/

#include "tekpaint.h"

void	destroy_tekpaint(t_tek *tekpaint)
{
  bunny_delete_clipable(&tekpaint->img->clipable);
  bunny_delete_clipable(&tekpaint->palette->clipable);
  destroy_toolbar(&tekpaint->toolbar);
  destroy_paintbar(&tekpaint->paintbar);
  destroy_event(tekpaint->mouse.zone);
}

void	destroy_event(t_bunny_position **zone)
{
  int	i;

  i = 0;
  while (i != NB_EVENT)
    bunny_free(zone[i++]);
}

void	destroy_paintbar(t_paintbar *paintbar)
{
  bunny_delete_clipable(&paintbar->background->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.pcolors.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.square.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.circle.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.line.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.eraser.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.brush.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.minus.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.more.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.tsquare.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.bucket.button->clipable);
  bunny_delete_clipable(&paintbar->buttons_paintbar.nsquare.button->clipable);
}

void	destroy_toolbar(t_toolbar *toolbar)
{
  bunny_delete_clipable(&toolbar->background->clipable);
  bunny_delete_clipable(&toolbar->buttons_toolbar.newfile.button->clipable);
  bunny_delete_clipable(&toolbar->buttons_toolbar.folder.button->clipable);
  bunny_delete_clipable(&toolbar->buttons_toolbar.save.button->clipable);
  bunny_delete_clipable(&toolbar->buttons_toolbar.cancel.button->clipable);
}
