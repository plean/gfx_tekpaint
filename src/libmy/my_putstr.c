/*
** my_putstr.c for my_putstr in /home/bailly_j/rendu/lib/sources
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Wed Oct  7 10:54:14 2015 Jamy Bailly
** Last update Mon Nov 16 11:27:38 2015 Jamy Bailly
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (str == 0)
    return (0);
  while (str[i] != '\0')
    {
      c = c + my_putchar(str[i]);
      i = i + 1;
    }
  return (c);
}
