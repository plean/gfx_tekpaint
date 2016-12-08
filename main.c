/*
** main.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Thu Jan 14 22:54:06 2016 Jamy Bailly
** Last update Sat Jan 30 23:41:46 2016 Jean PLANCHER
*/

#include "tekpaint.h"
#include "toolbar.h"
#include "paintbar.h"

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym key,
			    void *data)
{
  t_tek			*my_data;

  my_data = (t_tek*)data;
  if (state == GO_DOWN && key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  else if (key == BKS_PAGEUP)
    {
      if (my_data->bool_data.alpha + 10 <= 127)
	my_data->bool_data.alpha += 10;
      else
	my_data->bool_data.alpha = 127;
    }
  else if (key == BKS_PAGEDOWN)
    {
      if (my_data->bool_data.alpha - 10 >= 10)
	my_data->bool_data.alpha -= 10;
      else
	my_data->bool_data.alpha = 10;
    }
  return (GO_ON);
}

t_bunny_response	mainloop(void *tp)
{
  t_tek			*tekpaint;

  tekpaint = tp;
  if (tekpaint->press)
    {
      event_boot(tekpaint);
      tekpaint->press = 2;
    }
  toolbar_blit(&tekpaint->toolbar, &tekpaint->win.window->buffer);
  paintbar_blit(&tekpaint->paintbar, &tekpaint->win.window->buffer);
  img_blit(tekpaint->img, &tekpaint->win.window->buffer);
  paintbar_blit(&tekpaint->paintbar, &tekpaint->win.window->buffer);
  bunny_display(tekpaint->win.window);
  return (GO_ON);
}

int	main()
{
  t_tek	tekpaint;

  set_max_heap_size(100);
  if ((create_toolbar(&tekpaint.toolbar)) == -1 ||
      (create_paintbar(&tekpaint.paintbar)) == -1)
    return (0);
  create_window(&tekpaint.win);
  create_img(&tekpaint.img);
  if ((create_event_mouse(&tekpaint)) == -1)
    return (0);
  init_bool(&tekpaint.bool_data);
  tekpaint.palette = bunny_load_pixelarray("res/pcolors.bmp");
  bunny_set_loop_main_function(&mainloop);
  bunny_set_key_response(&key);
  bunny_set_click_response(&mouse_click);
  bunny_loop(tekpaint.win.window, 250, &tekpaint);
  bunny_stop(tekpaint.win.window);
  destroy_tekpaint(&tekpaint);
  return (0);
}
