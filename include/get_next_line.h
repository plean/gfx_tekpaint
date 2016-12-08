/*
** get_next_line.h for  in /home/bailly_j/rendu/B1-C-Prog-Elem/CPE_2015_getnextline
** 
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
** 
** Started on  Sun Jan 17 19:21:34 2016 Jamy Bailly
** Last update Sun Jan 17 22:43:05 2016 Jamy Bailly
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
# define READ_SIZE (1234567)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);
char	*return_null_or_zero(char *line, int i, int len_read, int len_line);
char	*gnl_strcpy(char *src, char c, int len_line);
int	gnl_read(char *buffer, const int fd, int *i);

#endif /* !GET_NEXT_LINE_H_ */
