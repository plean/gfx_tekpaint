/*
** my_putchar.c for my_putchar in /home/bailly_j/rendu/lib/sources
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Wed Oct  7 10:51:54 2015 Jamy Bailly
** Last update Mon Nov 16 10:50:49 2015 Jamy Bailly
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}
