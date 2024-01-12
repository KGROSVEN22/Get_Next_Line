/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:42:07 by kgrosven          #+#    #+#             */
/*   Updated: 2024/01/12 16:06:15 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!aux)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		aux[j++] = buffer[i++];
	free(buffer);
	return (aux);
}

char	*read_line(char **buffer)
{
	char	*line;
	int		count;

	count = 0;
	if (!(*buffer)[count])
		return (NULL);
	while ((*buffer)[count] != '\n' && (*buffer)[count])
		count++;
	if (ft_strchr(*buffer, '\n') != NULL)
		count++;
	line = ft_calloc(count + 1, sizeof(char));
	if (line == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	count = 0;
	while ((*buffer)[count] != '\n' && (*buffer)[count])
	{
		line[count] = (*buffer)[count];
		count++;
	}
	if ((*buffer)[count] == '\n')
		line[count++] = '\n';
	return (line);
}

char	*ft_join_and_free(char *stash, char *readbuffer)
{
	char	*aux;

	aux = ft_strjoin(stash, readbuffer);
	free(stash);
	return (aux);
}

char	*file_read(char *stash, int fd, int *error)
{
	char	*read_buffer;
	int		bytes;

	read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
	{
		*error = 1;
		return (NULL);
	}
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes] = 0;
		stash = ft_join_and_free(stash, read_buffer);
		if (!stash)
		{
			free(read_buffer);
			return (NULL);
		}
		if (ft_strchr(read_buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;
	int			error;

	error = 0;
	if (fd < 0 || read (fd, 0, 0) < 0 || BUFFER_SIZE < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	tmp = buffer;
	buffer = file_read(buffer, fd, &error);
	if (error)
		free(tmp);
	if (!buffer)
		return (NULL);
	line = read_line(&buffer);
	if (!buffer)
		return (NULL);
	buffer = next_line(buffer);
	return (line);
}
