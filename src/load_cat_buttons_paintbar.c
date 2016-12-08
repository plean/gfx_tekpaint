/*
** load_cat_buttons_paintbar.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Wed Jan 27 00:52:12 2016 Jamy Bailly
** Last update Wed Jan 27 01:36:57 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "paintbar.h"

void	load_buttons_palette_paintbar(t_buttons_paintbar *bts_paintbar,
				      t_bunny_position *button_pos,
				      int *s)
{
  button_pos->x = 15;
  button_pos->y = 120;
  *s = load_button("res/pcolors.bmp", button_pos, &bts_paintbar->pcolors);
}

void	load_buttons_shape_paintbar(t_buttons_paintbar *bts_paintbar,
				    t_bunny_position *button_pos,
				    int *s)
{
  button_pos->x = 64;
  button_pos->y += 320;
  *s = load_button("res/square.bmp", button_pos, &bts_paintbar->square);
  button_pos->x += 104;
  *s = load_button("res/circle.bmp", button_pos, &bts_paintbar->circle);
  button_pos->x += 104;
  *s = load_button("res/line.bmp", button_pos, &bts_paintbar->line);
}

void	load_buttons_tool_paintbar(t_buttons_paintbar *bts_paintbar,
				   t_bunny_position *button_pos,
				   int *s)
{
  button_pos->x = 101;
  button_pos->y += 94;
  *s = load_button("res/eraser.bmp", button_pos, &bts_paintbar->eraser);
  button_pos->x += 134;
  *s = load_button("res/brush.bmp", button_pos, &bts_paintbar->brush);
}

void	load_buttons_thickness_paintbar(t_buttons_paintbar *bts_paintbar,
					t_bunny_position *button_pos,
					int *s)
{
  button_pos->x = 101;
  button_pos->y += 94;
  *s = load_button("res/minus.bmp", button_pos, &bts_paintbar->minus);
  button_pos->x += 134;
  *s = load_button("res/more.bmp", button_pos, &bts_paintbar->more);
}

void	load_buttons_trans_paintbar(t_buttons_paintbar *bts_paintbar,
				    t_bunny_position *button_pos,
				    int *s)
{
  button_pos->x = 64;
  button_pos->y += 94;
  *s = load_button("res/tsquare.bmp", button_pos, &bts_paintbar->tsquare);
  button_pos->x += 104;
  *s = load_button("res/bucket.bmp", button_pos, &bts_paintbar->bucket);
  button_pos->x += 104;
  *s = load_button("res/nsquare.bmp", button_pos, &bts_paintbar->nsquare);
}
