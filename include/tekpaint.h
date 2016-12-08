/*
** tekpaint.h for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/include
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Thu Jan 14 22:45:56 2016 Jamy Bailly
** Last update Sat Jan 30 14:44:02 2016 Jamy Bailly
*/

#ifndef TEKPAINT_H_
# define TEKPAINT_H_

# include <lapin.h>
# include "toolbar.h"
# include "paintbar.h"
# include "my_list.h"

# ifndef NB_EVENT
# define NB_EVENT (16)
# endif /* !NB_EVENT */

# ifndef IMG_WIDTH
# define IMG_WIDTH 1024
# endif /* !IMG_WIDTH */

# ifndef IMG_HEIGHT
# define IMG_HEIGHT 768
# endif /* !IMG_HEIGHT */

# ifndef WIN_WIDTH
# define WIN_WIDTH IMG_WIDTH + 400
# endif /* !WIN_WIDTH */

# ifndef WIN_HEIGHT
# define WIN_HEIGHT IMG_HEIGHT + 84
# endif /* !WIN_HEIGHT */

# ifndef SHIFT_SIZE
# define SHIFT_SIZE 20
# endif /* !SHIFT_SIZE */

typedef struct		s_data_win
{
  t_bunny_window	*window;
  int			x;
  int			y;
}			t_data_win;

typedef struct          s_line_box
{
  t_bunny_position      pos;
  int                   dx;
  int                   dy;
  int                   sx;
  int                   sy;
  int                   err;
  int                   tmp;
}                       t_line_box;

typedef struct		s_event_mouse
{
  t_bunny_position	*zone[NB_EVENT];
  int			(*func_event[NB_EVENT])(void *tekpaint,
						struct s_event_mouse *actions);
  t_bunny_response	event_response;
  t_bunny_position	*mouse_pos;
}			t_event_mouse;

typedef struct		s_bool
{
  int			size;
  int			square;
  int			circle;
  int			line;
  int			eraser;
  int			brush;
  int			bucket;
  char			alpha;
  int			precision;
  unsigned int		color;
  t_bunny_position	pos[2];
}			t_bool;

typedef struct		s_tek
{
  t_data_win		win;
  t_toolbar		toolbar;
  t_paintbar		paintbar;
  t_bunny_pixelarray	*palette;
  t_bunny_pixelarray	*img;
  t_event_mouse		mouse;
  t_bool		bool_data;
  unsigned char		press;
}			t_tek;

void			set_max_heap_size(size_t);
void			create_img(t_bunny_pixelarray **img);
void			img_blit(t_bunny_pixelarray *img,
				 t_bunny_buffer *buffer);
void			print_mouse_position(void);
t_bunny_response	mouse_click(t_bunny_event_state state,
				    t_bunny_mousebutton button,
				    void *data);
int			create_event_mouse(t_tek *tekpaint);
t_bunny_position	*create_frame(t_bunny_position *pos,
				      t_bunny_pixelarray *img);
void			init_event_palette(t_tek *tekpaint);
void			init_event_shape(t_tek *tekpaint);
void			init_event_tool(t_tek *tekpaint);
void			init_event_thickness(t_tek *tekpaint);
void			init_event_trans(t_tek *tekpaint);
void			init_event_toolbar(t_tek *tekpaint);
void			event_boot(t_tek *tekpaint);
int			event_newfile(void *tekpaint, t_event_mouse *action);
int			event_folder(void *tekpaint, t_event_mouse *action);
int			event_save(void *tekpaint, t_event_mouse *action);
int			event_exit(void *tekpaint, t_event_mouse *action);
int			event_blackwhite(void *tp, t_event_mouse *action);
int			event_reverse(void *tekpaint, t_event_mouse *action);
void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color);
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color);
int			create_window(t_data_win *winbox);
void			set_background(t_bunny_pixelarray *pix, int color);
int			set_color(int r, int g, int b, int a);
void			destroy_tekpaint(t_tek *tekpaint);
void			destroy_event(t_bunny_position **zone);

/* BOOL */
int			event_square(void *tekpaint, t_event_mouse *action);
int			event_line(void *tekpaint, t_event_mouse *action);
int			event_circle(void *tekpaint, t_event_mouse *action);
int			event_bucket(void *tekpaint, t_event_mouse *action);
int			event_brush(void *tekpaint, t_event_mouse *action);
int			event_eraser(void *tekpaint, t_event_mouse *action);
int			event_more(void *tekpaint, t_event_mouse *action);
int			event_minus(void *tekpaint, t_event_mouse *action);
int			event_palette(void *tekpaint, t_event_mouse *action);
int			event_img(void *tekpaint, t_event_mouse *action);
void			init_bool(t_bool *bool_data);

void			my_blit_pixel(t_bunny_pixelarray *out,
				      const t_bunny_pixelarray *in,
				      t_bunny_position *pix);
#endif /* !TEKPAINT_H_ */
