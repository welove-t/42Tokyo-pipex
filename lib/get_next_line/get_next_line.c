/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:37:11 by terabu            #+#    #+#             */
/*   Updated: 2022/11/10 14:13:16 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_save(char **save)
{
	if (*save != NULL)
	{
		free(*save);
		*save = NULL;
	}
	return (NULL);
}

static char	*readline(char **save)
{
	char	*line;
	char	*tmp;
	char	*nextpoint;

	line = *save;
	nextpoint = *save;
	while (*nextpoint != '\n' && *nextpoint != '\0')
		nextpoint++;
	line = ft_strldup(*save, nextpoint - *save + 1);
	if (*nextpoint == '\n')
		tmp = ft_strldup(nextpoint + 1, ft_strlen(nextpoint));
	else
		tmp = NULL;
	free_save(save);
	*save = tmp;
	if (line == NULL)
		return (NULL);
	if (*line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*readbuff(int fd, char **save)
{
	char	*buf;
	char	*tmp;
	ssize_t	rc;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	rc = 1;
	while (!ft_strchr(*save, '\n') && rc != 0)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc == -1)
		{
			free(buf);
			return (free_save(save));
		}
		buf[rc] = '\0';
		tmp = ft_strjoin(*save, buf);
		free_save(save);
		*save = tmp;
	}
	free(buf);
	if (save == NULL || *save == NULL)
		return (NULL);
	return (readline(save));
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX + 1];

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	return (readbuff(fd, &save[fd]));
}
