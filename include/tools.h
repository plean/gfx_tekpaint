/*
** tools.h for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/include
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed Jan 27 02:41:50 2016 Jamy Bailly
** Last update Wed Jan 27 08:15:54 2016 David Zeng
*/

#ifndef TOOLS_H_
# define TOOLS_H_

unsigned int	my_get_color(t_bunny_pixelarray *pix,
			     int x,
			     int y);
void		whallacmarrant(t_bunny_pixelarray *pix,
			       t_bunny_position *pos,
			       t_color *t);
void		tekpinceaux_rond(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color,
				 int taille);
void		tekpinceaux_line(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 unsigned int color,
				 int taille);
void		tekpinceaux_carre(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  unsigned int color,
				  int taille);
void		tekbucket(t_bunny_pixelarray *pix,
			  t_bunny_position *pos1,
			  unsigned int old_color,
			  unsigned int new_color);
void		tekreverse(t_bunny_pixelarray *pix);
int		if_in_array(t_bunny_pixelarray *pix, int x, int y);
void		tekblackwhite(t_bunny_pixelarray *pix);

#endif /* !TOOLS_H_ */
