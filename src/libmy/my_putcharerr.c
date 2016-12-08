/*
** my_putcharerr.c for  in /home/bailly_j/rendu/lib/my/src
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Mon Dec 14 17:37:49 2015 Jamy Bailly
** Last update Mon Dec 14 17:43:33 2015 Jamy Bailly
*/

#include <unistd.h>

void	my_putcharerr(char ce)
{
  write(2, &ce, 1);
}
