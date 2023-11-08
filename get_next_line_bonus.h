/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:54:10 by ekose             #+#    #+#             */
/*   Updated: 2023/11/08 17:53:05 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX
#  define MAX 4096
# endif

# include <stdlib.h>
# include <unistd.h>

char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char	const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
char		*ft_polish(char *line);
char		*ft_line_read(int fd, char *buf, char *reserv);

#endif
