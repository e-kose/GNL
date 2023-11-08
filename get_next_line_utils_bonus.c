/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekose <ekose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:53:49 by ekose             #+#    #+#             */
/*   Updated: 2023/11/08 14:45:10 by ekose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	int		j;
	char	*p;

	if (!s1 && !s2)
		return (ft_strdup(""));
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = ft_strlen(s1);
	p = malloc(sizeof(char) * (len) + 1);
	if (!p)
		return (0);
	ft_memcpy(p, s1, ft_strlen(s1));
	while (i < ft_strlen(s2))
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sourc;

	i = 0;
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	if (!dest && !sourc)
		return (0);
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == s[i])
		return ((char *)s + i);
	return (0);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*p;

	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	i = 0;
	p = malloc((sizeof(char)) * (len + 1));
	if (p == NULL)
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
