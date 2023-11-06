/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:21:33 by ekose             #+#    #+#             */
/*   Updated: 2023/11/06 15:42:43 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
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
char	*ft_polish(char *line);
char	*ft_line_read(int fd, char *buf, char *reserv);

#endif
