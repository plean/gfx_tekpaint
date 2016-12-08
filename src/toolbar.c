/*
** toolbar.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Sat Jan 16 15:10:19 2016 Jamy Bailly
** Last update Sat Jan 30 16:27:59 2016 Jamy Bailly
*/

#include "tekpaint.h"
#include "toolbar.h"

int	create_toolbar(t_toolbar *toolbar)
{
  toolbar->background = bunny_new_pixelarray(WIN_WIDTH, 84);
  set_background(toolbar->background, set_color(0, 0, 0, 0));
  return (load_buttons_toolbar(&toolbar->buttons_toolbar));
}

void			toolbar_blit(t_toolbar *toolbar,
				     t_bunny_buffer *buffer)
{
  t_bunny_position	toolbar_pos;

  toolbar_pos.x = 0;
  toolbar_pos.y = 0;
  bunny_blit(buffer, &toolbar->background->clipable, &toolbar_pos);
  blit_buttons_toolbar(&toolbar->buttons_toolbar, buffer);
}

int			load_buttons_toolbar(t_buttons_toolbar *bts_toolbar)
{
  t_bunny_position	button_pos;
  int			s;

  button_pos.x = 38;
  button_pos.y = 10;
  s = load_button("res/newfile.bmp", &button_pos, &bts_toolbar->newfile);
  button_pos.x += 124;
  s += load_button("res/folder.bmp", &button_pos, &bts_toolbar->folder);
  button_pos.x += 124;
  s += load_button("res/save.bmp", &button_pos, &bts_toolbar->save);
  button_pos.x = WIN_WIDTH - 74;
  s += load_button("res/cancel.bmp", &button_pos, &bts_toolbar->cancel);
  if (s < 0)
    return (-1);
  else
    return (0);
}

void	blit_buttons_toolbar(t_buttons_toolbar *b_tb,
			     t_bunny_buffer *buf)
{
  bunny_blit(buf, &b_tb->newfile.button->clipable, &b_tb->newfile.button_pos);
  bunny_blit(buf, &b_tb->folder.button->clipable, &b_tb->folder.button_pos);
  bunny_blit(buf, &b_tb->save.button->clipable, &b_tb->save.button_pos);
  bunny_blit(buf, &b_tb->cancel.button->clipable, &b_tb->cancel.button_pos);
}
