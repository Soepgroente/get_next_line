/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vincent@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 17:28:35 by vincent       #+#    #+#                 */
/*   Updated: 2024/01/14 18:30:56 by vincent       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void clean_up(char ***buffer)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		free(*buffer[i]);
		*buffer[i] = NULL;
		i++;
	}
	free(*buffer);
	*buffer = NULL;
}

static void	init_static(char ***buffer)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *buffer;
	tmp = malloc(1024 * sizeof(char *));
	if (tmp == NULL)
		return (NULL);
	while (i < 1024)
	{
		tmp[i] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (tmp[i] == NULL)
			return (clean_up(buffer), NULL);
		i++;
	}
}

char	*read_stuff(int fd, char *line, char *buffer, char *tmp)
{
	int		bytes_read;

	bytes_read = 0;
	if (buffer[0] != '\0')
		line = combine_strings(buffer, "");
	if (line == NULL)
		return (free(tmp), NULL);
	while (find_newl(buffer) == NOT_FOUND && bytes_read == BUFFER_SIZE)	
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			buffer[0] = '\0';
			free(line);
			return (NULL);
		}
		line = combine_strings(tmp, buffer);
		if (line == NULL)
			return (free(tmp), NULL);
		free(tmp);
		tmp = line;		
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	**buffer = {NULL};
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
		init_static(&buffer);
	line = malloc(1 * sizeof(char));
	if (line == NULL)
		return (NULL);
	line = read_stuff(fd, line, buffer[fd], line);
	if (line == NULL)
		return (NULL);
	copy_paste(buffer[fd], &buffer[fd][find_newl(buffer) + 1]);
	if (*line == '\0')
		return (free(line), NULL);
	return (line);
}