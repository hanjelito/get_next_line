/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:42:15 by juan-gon          #+#    #+#             */
/*   Updated: 2020/02/25 14:13:57 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *c)
{
	char	*newc;
	int		count;
	int		len;

	len = ft_strlen(c);
	if (!(newc = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	count = 0;
	while (c[count])
	{
		newc[count] = c[count];
		count++;
	}
	newc[count] = '\0';
	return (newc);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_clen(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	char	*dst;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len = ((ft_strlen(s + start) < len) ? ft_strlen(s + start) : len);
	if ((dst = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	count = 0;
	while (count < len)
	{
		*(dst + count) = *(s + count + start);
		count++;
	}
	*(dst + count) = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*j;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = (char *)malloc(sizeof(*j) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j)
		return (NULL);
	while (*s1)
		j[i++] = *s1++;
	while (*s2)
		j[i++] = *s2++;
	j[i] = '\0';
	return (j);
}
