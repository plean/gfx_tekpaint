/*
** toolbar.h for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/include
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue Jan 26 18:37:30 2016 Jamy Bailly
** Last update Wed Jan 27 08:15:35 2016 David Zeng
*/

#ifndef TOOLBAR_H_
# define TOOLBAR_H_

# include "button.h"

typedef struct		s_buttons_toolbar
{
  t_button		newfile;
  t_button		folder;
  t_button		save;
  t_button		cancel;
}			t_buttons_toolbar;

typedef struct		s_toolbar
{
  t_bunny_pixelarray	*background;
  t_buttons_toolbar	buttons_toolbar;
}			t_toolbar;

int	create_toolbar(t_toolbar *toolbar);
int	load_buttons_toolbar(t_buttons_toolbar *buttons_toolbar);
void	toolbar_blit(t_toolbar *toolbar,
		     t_bunny_buffer *buffer);
void	blit_buttons_toolbar(t_buttons_toolbar *buttons_toolbar,
			     t_bunny_buffer *buffer);
void	destroy_toolbar(t_toolbar *toolbar);

#endif /* !TOOLBAR_H_ */
