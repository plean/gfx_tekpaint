/*
** read.c for  in /home/albert_q/rendu/infographie/gfx_tekpaint/add_later/albert_q/BMP
**
** Made by Quentin Albertone
** Login   <albert_q@epitech.net>
**
** Started on  Tue Jan 26 01:00:02 2016 Quentin Albertone
** Last update Wed Jan 27 08:34:55 2016 David Zeng
*/

#include <stdio.h>
#include "bmp.h"

t_file		*initstruct(int fd)
{
  t_file	*file;
  int		size;
  char		buffer[50];

  size = 0;
  if ((file = bunny_malloc(sizeof(t_file))) == NULL)
    return (NULL);
  size += read(fd, &file->signe, 2);
  size += read(fd, &file->size, 4);
  size += read(fd, &file->reserve, 4);
  size += read(fd, &file->shift, 4);
  size += read(fd, &file->size_head, 4);
  size += read(fd, &file->width, 4);
  size += read(fd, &file->height, 4);
  size += read(fd, &file->plan, 2);
  size += read(fd, &file->nb_bit_pixel, 4);
  size += read(fd, &file->compress, 2);
  size += read(fd, &file->size_picture, 4);
  size += read(fd, &file->color_pal, 4);
  size += read(fd, &file->nb_color_im, 4);
  if (file->shift - size >= 0)
    read(fd, buffer, file->shift - size);
  return (file);
}

t_bunny_pixelarray	*my_load_bmp(char *filename)
{
  int		fd;
  t_file	*file;

  if ((fd = open(filename, O_RDONLY)) <= 2)
    {
      write(2, "Wrong image\n", my_strlen("Wrong image\n"));
      return (NULL);
    }
  if ((file = initstruct(fd)) == NULL)
    return (NULL);
  return (my_write_bmp(file, fd));
}
