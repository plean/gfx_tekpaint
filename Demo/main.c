/*
** main.c<Extra> for main in /home/zeng_d/rendu/Info/gfx_tekpaint
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Wed Jan 27 08:41:37 2016 David Zeng
** Last update Sat Jan 30 17:26:50 2016 David Zeng
*/

#include <lapin.h>
#include "bmp.h"

int	main(int argc, char **argv)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;

  if (argc != 2)
    {
      write(2, "USAGE: ./bmp [BMP]\n", 19);
      return (1);
    }
  pos.x = 0;
  pos.y = 0;
  if ((pix = my_load_bmp(argv[1])) == NULL)
    {
      return (1);
    }
  win = bunny_start_style(pix->clipable.clip_width,
			  pix->clipable.clip_height, 1 | 4 , "t");
  bunny_blit(&win->buffer, &pix->clipable, &pos);
  bunny_display(win);
  bunny_loop(win, 60, win);
  bunny_stop(win);
  return (0);
}
