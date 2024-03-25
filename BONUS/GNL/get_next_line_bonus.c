/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouddach <zouddach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:46:11 by zouddach          #+#    #+#             */
/*   Updated: 2023/12/02 10:46:17 by zouddach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	when_recall(char **buffer, char **line)
{
	if (ft_strchr(*buffer, '\n'))
	{
		if (*(ft_strchr(*buffer, '\n') + 1))
		{
			*buffer = ft_trim(*buffer);
			*line = ft_strjoin(*buffer, NULL);
			if (!**buffer)
			{
				free(*buffer);
				*buffer = NULL;
			}
		}
	}
	else
	{
		*line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
}

char	*save_line(char **line, char **buffer, int fd)
{
	int	read_bytes;

	while (1)
	{
		if (ft_strchr(*line, '\n'))
			return (*line);
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		if (read_bytes == 0)
			return (free(buffer[fd]), buffer[fd] = NULL, *line);
		buffer[fd][read_bytes] = '\0';
		*line = ft_strjoin(buffer[fd], *line);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > 2147483647)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	line = NULL;
	if (buffer[fd] != NULL)
		when_recall(&buffer[fd], &line);
	if (buffer[fd] == NULL)
	{
		buffer[fd] = malloc((size_t)BUFFER_SIZE + 1);
		if (!buffer[fd])
			return (NULL);
	}
	return (save_line(&line, buffer, fd));
}
