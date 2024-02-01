/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vincent@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 17:28:35 by vincent       #+#    #+#                 */
/*   Updated: 2024/02/01 20:08:02 by vvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_and_null(char **var)
{
	free(*var);
	*var = NULL;
}

static void	manage_buffer(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (find_newl(dest) == NOT_FOUND)
	{
		dest[0] = '\0';
		return ;
	}
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static char	*read_stuff(t_data *data, int fd, char *line, char **buffer)
{
	int		bytes_read;

	bytes_read = 1;
	if (*buffer == NULL)
	{
		*buffer = ft_realloc(*buffer, BUFFER_SIZE + 1);
		if (*buffer == NULL)
			return (NULL);
	}
	line = combine_strings(data, line, *buffer);
	if (line == NULL)
		return (NULL);
	data->len = get_length(line);
	while (find_newl(*buffer) == NOT_FOUND && bytes_read != 0)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), NULL);
		(*buffer)[bytes_read] = '\0';
		line = combine_strings(data, line, *buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024] = {NULL};
	t_data		data;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	data.size = BUFFER_SIZE + 1;
	data.len = BUFFER_SIZE;
	data.line = read_stuff(&data, fd, NULL, &buffer[fd]);
	if (data.line == NULL)
		return (free_and_null(&buffer[fd]), NULL);
	manage_buffer(buffer[fd], &(buffer[fd][find_newl(buffer[fd]) + 1]));
	data.line = ft_realloc(data.line, get_length(data.line) + 1);
	if (data.line == NULL || *data.line == '\0')
	{
		free(data.line);
		free_and_null(&buffer[fd]);
		return (NULL);
	}
	return (data.line);
}
