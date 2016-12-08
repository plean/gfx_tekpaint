/*
** list.h for  in /home/planch_j/rendu/Info/gfx_tekpaint/include
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Fri Jan 29 06:40:48 2016 Jean PLANCHER
** Last update Fri Jan 29 15:02:07 2016 Jean PLANCHER
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

# include <lapin.h>

typedef struct		s_element
{
  t_bunny_position	pos;
  struct s_element	*nxt;
}			t_element;

#endif /* !MY_LIST_H_ */
