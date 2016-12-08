/*
** img.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Sat Jan 16 15:10:09 2016 Jamy Bailly
** Last update Sat Jan 30 14:44:14 2016 Jamy Bailly
*/

#include "tekpaint.h"

void	create_img(t_bunny_pixelarray **img)
{
  *img = bunny_new_pixelarray(IMG_WIDTH, IMG_HEIGHT);
  set_background(*img, set_color(255, 255, 255, 0));
}

void			img_blit(t_bunny_pixelarray *img,
				 t_bunny_buffer *buffer)
{
  t_bunny_position	img_pos;

  img_pos.x = 400;
  img_pos.y = 84;
  bunny_blit(buffer, &img->clipable, &img_pos);
}
