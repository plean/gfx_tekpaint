/*
** get_nbr.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell1
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Sun Jan 24 17:22:23 2016 Jean PLANCHER
** Last update Tue Jan 26 17:48:44 2016 David Zeng
*/

#include <unistd.h>
#include "bmp.h"

unsigned int     get_number(char *str, unsigned int nb, int i)
{
  while (str[++i])
    nb = nb * 10 + (str[i] - 48);
  return (nb);
}

unsigned int     my_getnbr(char *str)
{
  if (str == NULL || (str[0] == 48 && str[1] == 0))
    return (0);
  return (get_number(str, 0, -1 + (str[0] == '-')) *
	 ((str[0] == '-') * -2 + 1));
}

int		my_strlen(char *str)
{
  int		i;

  i = -1;
  while (str[++i]);
  return (i);
}
