/*
** my_load_bmp.c for load bmp in /home/zeng_d
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Jan 26 14:29:31 2016 David Zeng
** Last update Tue Jan 26 18:44:06 2016 David Zeng
*/

#include "bmp.h"

unsigned int		my_get_img(char *buffer, int read_size)
{
  t_color		color;

  color.argb[2] = buffer[0];
  color.argb[1] = buffer[1];
  color.argb[0] = buffer[2];
  if (read_size > 3)
    color.argb[3] = buffer[3];
  return (color.full);
}

t_bunny_pixelarray	*my_write_bmp(t_file *bmp, int fd)
{
  t_bunny_pixelarray	*pix;
  t_bunny_position	pos;
  char			buffer[5];
  unsigned int		*pixels;
  int			read_size;

  pix = bunny_new_pixelarray(bmp->width, bmp->height);
  pixels = (unsigned int*)pix->pixels;
  pos.y = bmp->height - 1;
  read_size = bmp->nb_bit_pixel / 8;
  if (read_size == 0)
    read_size = 1;
  while (pos.y >= 0)
    {
      pos.x = 0;
      while (pos.x < bmp->width)
	{
	  if ((read(fd, buffer, read_size)) != -1)
	    pixels[pos.y * bmp->width + pos.x] = my_get_img(buffer, read_size);
	  pos.x += 1;
	}
      pos.y -= 1;
    }
  bunny_free(bmp);
  return (pix);
}
