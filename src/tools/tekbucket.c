/*
** bucket.c for  in /home/planch_j/rendu/Info/gfx_tekpaint/src/tools
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Jan 29 14:15:34 2016 Jean PLANCHER
** Last update Fri Jan 29 15:01:48 2016 Jean PLANCHER
*/

#include "tekpaint.h"
#include "tools.h"

t_element		*edit_mylist(t_element **list,
				     int x,
				     int y)
{
  t_element		*elem;
  t_bunny_position	pos;

  if ((elem = bunny_malloc(sizeof(t_element))) == NULL)
    return (NULL);
  pos.x = x;
  pos.y = y;
  elem->pos = pos;
  elem->nxt = *list;
  return (elem);
}

t_bunny_position        print_mylist(t_bunny_pixelarray *pix,
				     t_element *list,
				     unsigned int color)
{
  t_bunny_position	pos;
  t_color		c;

  c.full = color;
  c.argb[3] = 0xFF;
  whallacmarrant(pix, &list->pos, &c);
  pos = list->pos;
  return (pos);
}

t_element	*del_mylist(t_element *list)
{
  t_element	*tmp;

  tmp = list->nxt;
  bunny_free(list);
  list = tmp;
  return (list);
}

void		tekbucket(t_bunny_pixelarray *pix,
			  t_bunny_position *pos,
			  unsigned int old_color,
			  unsigned int new_color)
{
  t_element	*element;

  if ((element = bunny_malloc(sizeof(t_element))) == NULL)
      return ;
  element = NULL;
  if (my_get_color(pix, pos->x, pos->y) == old_color)
    {
      element = edit_mylist(&element, pos->x, pos->y);
      while (element != NULL)
	{
	  *pos = print_mylist(pix, element, new_color);
	  element = del_mylist(element);
	  if (my_get_color(pix, pos->x + 1, pos->y) == old_color)
	    element = edit_mylist(&element, pos->x + 1, pos->y);
	  if (my_get_color(pix, pos->x, pos->y + 1) == old_color)
	    element = edit_mylist(&element, pos->x, pos->y + 1);
	  if (my_get_color(pix, pos->x - 1, pos->y) == old_color)
	    element = edit_mylist(&element, pos->x - 1, pos->y);
	  if (my_get_color(pix, pos->x, pos->y - 1) == old_color)
	    element = edit_mylist(&element, pos->x, pos->y - 1);
	}
    }
}
