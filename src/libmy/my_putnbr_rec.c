/*
** my_putnbr_rec.c for tekpaint in /home/bailly_j/rendu/B1-Infographie/gfx_tekpaint/src/libmy
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Sat Jan 16 23:10:38 2016 Jamy Bailly
** Last update Sat Jan 16 23:14:49 2016 Jamy Bailly
*/

#include "my.h"

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = 0 - nb;
    }
  if (nb >= 10)
    {
      my_putnbr(nb / 10);
    }
  my_putchar((nb % 10) + 48);
}
