/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:52:27 by ekose             #+#    #+#             */
/*   Updated: 2023/11/08 17:53:19 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_line_read(int fd, char *buf, char *reserv)
{
	char	*temp;
	int		readed;

	readed = 1;
	while (readed)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(reserv);
			return (NULL);
		}
		else if (readed == 0)
			break ;
		buf[readed] = '\0';
		if (reserv == NULL)
			reserv = ft_strdup("");
		temp = reserv;
		reserv = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (reserv);
}

char	*ft_polish(char *line)
{
	char	*cleaned;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != 0)
		i++;
	if (line[i] == 0)
		return (NULL);
	cleaned = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (cleaned == NULL)
		return (NULL);
	if (cleaned[0] == 0)
	{
		free(cleaned);
		cleaned = NULL;
		return (NULL);
	}
	line[i + 1] = 0;
	return (cleaned);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*reserv[MAX];

	if (fd < 0 || BUFFER_SIZE < 1 || fd > MAX)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	line = ft_line_read(fd, buf, reserv[fd]);
	free(buf);
	buf = NULL;
	if (line == NULL)
	{
		reserv[fd] = NULL;
		return (NULL);
	}
	reserv[fd] = ft_polish(line);
	return (line);
}
