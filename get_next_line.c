/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-gon <juan-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:33:54 by juan-gon          #+#    #+#             */
/*   Updated: 2020/02/25 14:17:02 by juan-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	add_line(char **save, int fd, char **line)
{
	char *temp;

	if (!save[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_clen(save[fd], '\n'))
	{
		*line = ft_substr(save[fd], 0, ft_strlen(save[fd])
			- (ft_strlen(ft_clen(save[fd], '\n'))));
		temp = ft_strdup(ft_clen(save[fd], '\n') + 1);
		free(save[fd]);
		save[fd] = temp;
		return (1);
	}
	else
		*line = ft_strdup(save[fd]);
	free(save[fd]);
	save[fd] = NULL;
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes_read;
	static char *save[4096];
	char		*temp;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0 ||
	!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))
	|| read(fd, buf, 0) == -1)
		return (-1);
	while ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes_read] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(save[fd], buf);
			free(save[fd]);
			save[fd] = temp;
		}
		if (ft_clen(buf, '\n'))
			break ;
	}
	free(buf);
	return (add_line(save, fd, line));
}
