/*
** safe.c for  in /home/albert_q/rendu/infographie/gfx_tekpaint/albert_q
**
** Made by Quentin Albertone
** Login   <albert_q@epitech.net>
**
** Started on  Wed Jan  6 13:01:03 2016 Quentin Albertone
** Last update Wed Jan 27 20:36:25 2016 Jean PLANCHER
*/

#include "bmp.h"

void	my_putchar_file(char c, int fd)
{
  write(fd, &c, 1);
}

void	my_putnbr_file(unsigned int nb, int fd)
{
  if (nb > 9)
    my_putnbr_file(nb / 10, fd);
  my_putchar_file((nb % 10) + 48, fd);
}

void		create_file(unsigned int *data,
			    char *filename,
			    t_bunny_pixelarray *pix)
{
  int		fd;
  int		i;
  int		size;

  size = (pix->clipable.clip_width * pix->clipable.clip_height);
  i = 0;
  if ((fd = open(filename, O_CREAT|O_WRONLY, MODE)) < 3)
    {
      write(2, "error open file", 15);
      return ;
    }
  write(fd, "[sauvegarde]\nsize=", 18);
  my_putnbr_file(size, fd);
  write(fd, "\nheight=", 8);
  my_putnbr_file(pix->clipable.clip_height, fd);
  write(fd, "\nwidth=", 7);
  my_putnbr_file(pix->clipable.clip_width, fd);
  write(fd, "\ndata=", 6);
  while (i < size)
    {
      my_putnbr_file(data[i], fd);
      write(fd, ",", 1);
      i = i + 1;
    }
  write(1, "save done\n", 10);
}

void		my_save(t_bunny_pixelarray *pix, char *filename)
{
  unsigned int	*data;
  int		i;
  int		size;

  i = 0;
  size = (pix->clipable.clip_width * pix->clipable.clip_height);
  data = bunny_malloc(sizeof(unsigned int) * (size + 1));
  if (data == NULL)
    return ;
  while (i < size)
    {
      data[i] = ((unsigned int *)pix->pixels)[i];
      i = i + 1;
    }
  create_file(data, filename, pix);
  bunny_free(data);
}
