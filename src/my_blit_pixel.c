/*
** my_blit_pixel.c for blit pixel in /home/zeng_d/test/Info/tmp
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Sun Nov  8 19:33:36 2015 David Zeng
** Last update Mon Jan 25 20:55:22 2016 David Zeng
*/

#include <lapin.h>

void	my_blit_pixel(t_bunny_pixelarray *out,
		      const t_bunny_pixelarray *in,
		      t_bunny_position *pos)
{
  int	tmp;
  int	pos_out;
  int	pos_in;
  int	pos_in_max;
  int	*pixel_out;
  int	*pixel_in;

  pixel_out = out->pixels;
  pixel_in = in->pixels;
  tmp = out->clipable.clip_width - in->clipable.clip_width;
  pos_out = (*pos).y * out->clipable.clip_width + (*pos).x;
  pos_in = 0;
  pos_in_max = in->clipable.clip_width * in->clipable.clip_height;
  while (pos_in != pos_in_max)
    {
      if (pos_in % in->clipable.clip_width == 0 && pos_in != 0)
	pos_out = pos_out + tmp;
      pixel_out[pos_out] = pixel_in[pos_in];
      pos_out++;
      pos_in++;
    }
}
