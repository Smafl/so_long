/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekulichk <ekulichk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:09:52 by ekulichk          #+#    #+#             */
/*   Updated: 2023/02/18 12:50:31 by ekulichk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_bonus.h"

int	gnl_find_chr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*gnl_get_leftover(int *end_position, char *line)
{
	int		left_size;
	char	*leftover;

	if (line == NULL)
		return (NULL);
	left_size = gnl_strlen(line) - *end_position + 1;
	if (left_size <= 1)
	{
		gnl_free(&line);
		return (NULL);
	}
	leftover = malloc(sizeof(char) * left_size);
	if (leftover == NULL)
	{
		gnl_free(&line);
		return (NULL);
	}
	gnl_memcpy(leftover, line + *end_position, left_size);
	gnl_free(&line);
	return (leftover);
}

char	*gnl_get_line(int *end_position, char *line)
{
	char	*result;

	if (line == NULL)
		return (NULL);
	*end_position = gnl_find_chr(line, '\n');
	if (*end_position == 0)
		*end_position = gnl_strlen(line);
	result = malloc(sizeof(char) * (*end_position + 1));
	if (result == NULL)
		return (NULL);
	gnl_memcpy(result, line, *end_position);
	result[*end_position] = '\0';
	return (result);
}

char	*gnl_read_line(int fd, char *line)
{
	int		read_bytes;
	char	*read_buf;

	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buf == NULL)
		return (NULL);
	while (gnl_find_chr(line, '\n') == 0)
	{
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			gnl_free(&read_buf);
			gnl_free(&line);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		read_buf[read_bytes] = '\0';
		line = gnl_strjoin(line, read_buf);
	}
	gnl_free(&read_buf);
	return (line);
}

char	*get_next_line(int fd)
{
	int			end_position;
	char		*result;
	static char	*line[MAX_FD];

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (line[fd] != NULL)
		{
			gnl_free(&line[fd]);
			line[fd] = NULL;
		}
		return (NULL);
	}
	line[fd] = gnl_read_line(fd, line[fd]);
	result = gnl_get_line(&end_position, line[fd]);
	line[fd] = gnl_get_leftover(&end_position, line[fd]);
	return (result);
}
