/*
** load_button.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Sat Jan 16 15:09:59 2016 Jamy Bailly
** Last update Tue Jan 26 19:16:42 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "button.h"

int	load_button(char *path,
		    t_bunny_position *button_pos,
		    t_button *button)
{
  if ((button->button = bunny_load_pixelarray(path)) != NULL)
    {
      button->button_pos.x = button_pos->x;
      button->button_pos.y = button_pos->y;
      return (0);
    }
  else
    return (-1);
}
