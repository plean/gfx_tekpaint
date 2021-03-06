/*
** get_next_line.c for  in /home/bailly_j/rendu/B1-C-Prog-Elem/CPE_2015_getnextline
**
** Made by
** Login   <bailly_j@epitech.net>
**
** Started on  Mon Jan  4 23:46:14 2016
** Last update Wed Jan 27 08:35:46 2016 David Zeng
*/

#include <lapin.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*gnl_strcpy(char *src, char c, int len_line)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = bunny_malloc(sizeof(char *) * (len_line + 1))) == NULL)
    return (NULL);
  while (i != len_line)
    {
      dest[i] = src[i];
      i++;
    }
  dest[len_line] = c;
  if (len_line != 0)
    bunny_free(src);
  return (dest);
}

int	gnl_read(char *buffer, const int fd, int *i)
{
  int	len_read;

  if ((len_read = read(fd, buffer, READ_SIZE)) < 0)
    return (-1);
  *i = 0;
  return (len_read);
}

char	*return_null_or_zero(char *line, int i, int len_read, int len_line)
{
  if (i - 1 == len_read && len_read != READ_SIZE && !line[i - 1])
    return (NULL);
  else
    return (gnl_strcpy(line, '\0', len_line));
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE];
  char		*line;
  int		len_line;
  static int	len_read;
  static int	i;

  len_line = 0;
  line = "";
  if (i == 0)
    len_read = ((len_read = gnl_read(buffer, fd, &i)) <= 0) ? 0 : len_read;
  while (len_read != 0)
    {
      if (i == len_read)
	len_read = ((len_read = gnl_read(buffer, fd, &i)) <= 0) ? 0 : len_read;
      if (buffer[i] == '\n' || (i == len_read && len_read != READ_SIZE))
	{
	  i++;
	  return (line = return_null_or_zero(line, i, len_read, len_line));
	}
      if ((line = gnl_strcpy(line, buffer[i], len_line)) == NULL)
	return (NULL);
      i++;
      len_line++;
    }
  return (NULL);
}
