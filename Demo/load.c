/*
** load.c for  in /home/albert_q/rendu/infographie/gfx_tekpaint/albert_q
**
** Made by Quentin Albertone
** Login   <albert_q@epitech.net>
**
** Started on  Wed Jan  6 14:23:37 2016 Quentin Albertone
** Last update Wed Jan 27 08:32:30 2016 David Zeng
*/

#include "bmp.h"

void		picture(unsigned int *data, t_bunny_pixelarray *pix)
{
  unsigned int	*pixels;
  int		i;

  i = 0;
  pixels = pix->pixels;
  while (i++ < (pix->clipable.clip_width * pix->clipable.clip_height))
    {
      pixels[i] = data[i];
    }
  bunny_free(data);
  write(1, "pixelarray done\n", 16);
}

unsigned int	*my_translate(t_bunny_ini *ini, unsigned int *data)
{
  int		size;
  int		i;

  i = 0;
  size = my_getnbr((char*)bunny_ini_get_field(ini, "sauvegarde", "size", 0));
  while (i < size)
    {
      data[i] = my_getnbr((char*)bunny_ini_get_field
			  (ini, "sauvegarde", "data", i));
      i = i + 1;
    }
  return (data);
}

t_bunny_pixelarray	*my_load(char *filename)
{
  t_bunny_pixelarray	*pix;
  t_bunny_ini		*load;
  unsigned int		*data;
  int			height;
  int			width;

  load =  bunny_load_ini(filename);
  if (load == NULL)
    {
      write(2, "error\n", 6);
      return (NULL);
    }
  width = my_getnbr((char*)bunny_ini_get_field(load, "sauvegarde", "width", 0));
  height = my_getnbr((char*)bunny_ini_get_field
		     (load, "sauvegarde", "height", 0));
  pix = bunny_new_pixelarray(width, height);
  if ((data = bunny_malloc(sizeof(int) * (width * height + 1))) == NULL)
    return (NULL);
  my_translate(load, data);
  picture(data, pix);
  return (pix);
}
