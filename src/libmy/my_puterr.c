/*
** my_puterr.c for  in /home/bailly_j/rendu/lib/my/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Mon Dec 14 17:32:56 2015 Jamy Bailly
** Last update Mon Dec 14 22:09:41 2015 Jamy Bailly
*/

#include "my.h"

void	my_puterr(char *err)
{
  int	i;

  i = 0;
  while (err[i] != '\0')
    {
      my_putcharerr(err[i]);
      i++;
    }
}
