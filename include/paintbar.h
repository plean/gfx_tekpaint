/*
** paintbar.h for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/include
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Tue Jan 26 18:37:50 2016 Jamy Bailly
** Last update Wed Jan 27 08:54:42 2016 Jean PLANCHER
*/

#ifndef PAINTBAR_H_
# define PAINTBAR_H_

# include "button.h"

typedef struct		s_buttons_paintbar
{
  t_button		pcolors;
  t_button		square;
  t_button		circle;
  t_button		line;
  t_button		eraser;
  t_button		brush;
  t_button		minus;
  t_button		more;
  t_button		tsquare;
  t_button		bucket;
  t_button		nsquare;
}			t_buttons_paintbar;

typedef struct		s_paintbar
{
  t_bunny_pixelarray	*background;
  t_buttons_paintbar	buttons_paintbar;
}			t_paintbar;

int	create_paintbar(t_paintbar *paintbar);
int	load_buttons_paintbar(t_buttons_paintbar *buttons_toolbar);
void	load_buttons_palette_paintbar(t_buttons_paintbar *bts_paintbar,
				      t_bunny_position *button_pos,
				      int *s);
void	load_buttons_shape_paintbar(t_buttons_paintbar *bts_paintbar,
				    t_bunny_position *button_pos,
				    int *s);
void	load_buttons_tool_paintbar(t_buttons_paintbar *bts_paintbar,
				   t_bunny_position *button_pos,
				   int *s);
void	load_buttons_thickness_paintbar(t_buttons_paintbar *bts_paintbar,
					t_bunny_position *button_pos,
					int *s);
void	load_buttons_trans_paintbar(t_buttons_paintbar *bts_paintbar,
				    t_bunny_position *button_pos,
				    int *s);
void	paintbar_blit(t_paintbar *paintbar,
		      t_bunny_buffer *buffer);
void	blit_buttons_paintbar(t_buttons_paintbar *i_tb,
			      t_bunny_buffer *buf);
void	destroy_paintbar(t_paintbar *paintbar);

#endif /* !PAINTBAR_H_ */
