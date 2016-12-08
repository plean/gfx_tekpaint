/*
** my_bunny.h for buny in /home/zeng_d/rendu/Info/lightning_2020
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Fri Nov 13 14:22:48 2015 David Zeng
** Last update Wed Jan 27 08:16:20 2016 David Zeng
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include <math.h>

#ifndef MY_BMP_H_
# define MY_BMP_H_

# ifndef MODE
# define MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
# endif /* !MODE */

typedef	struct		s_file
{
  char			signe[2];
  int			size;
  int			reserve;
  int			shift;
  int			size_head;
  int			width;
  int			height;
  char			plan[2];
  int			nb_bit_pixel;
  char			compress[2];
  int			size_picture;
  int			color_pal;
  int			nb_color_im;
}			t_file;

typedef	struct		s_write
{
  char			signe[2];
  int			size;
  int			reserve;
  int			shift;
  int			size_head;
  int			width;
  int			height;
  char			plan[2];
  char			nb_bit_pixel[2];
  int			compress;
  int			size_picture;
  int			color_pal;
  int			nb_color_im;
}			t_write;

/* load.c */
t_bunny_pixelarray      *my_load(char *filename);
unsigned int		*my_translate(t_bunny_ini *ini, unsigned int *data);
void			picture(unsigned int *data, t_bunny_pixelarray *pix);

/* save.c */
void			my_save(t_bunny_pixelarray *pix, char *filename);
void			create_file(unsigned int *data, char *filename,
				    t_bunny_pixelarray *pix);
void			my_putchar_file(char c, int fd);
void			my_putnbr_file(unsigned int nb, int fd);

/* LOAD BMP */
t_file			*initstruct(int fd);
t_bunny_pixelarray	*my_write_bmp(t_file *bmp, int fd);
t_bunny_pixelarray	*my_load_bmp(char *filename);

/* SAVE BMP */
void		save_bmp(t_bunny_pixelarray *pix, char *filename);

/* STR */
int			my_strlen(char *str);
unsigned int		my_getnbr(char *str);

#endif /* !MY_BMP_H_ */
