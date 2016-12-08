/*
** button.h for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/include
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue Jan 26 18:51:06 2016 Jamy Bailly
** Last update Wed Jan 27 08:16:08 2016 David Zeng
*/

#ifndef BUTTON_H_
# define BUTTON_H_

typedef struct		s_button
{
  t_bunny_pixelarray	*button;
  t_bunny_position	button_pos;
}			t_button;

int	load_button(char *path,
		    t_bunny_position *button_pos,
		    t_button *button);

#endif /* !BUTTON_H_ */
