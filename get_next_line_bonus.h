/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                           |o_o || |                */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/16 16:07:06 by svrielin      #+#    #+#                 */
/*   Updated: 2022/03/13 21:35:58 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 10240

char	*get_next_line(int fd);
size_t	ft_strlen(char const *string);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*create_empty_string(void);
char	*strdelete(char *str);
char	*newline(int fd, char **saved, int bytes_read);
int		readtillnewline(int fd, char **saved);

#endif
