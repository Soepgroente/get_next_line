/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vincent@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 17:28:35 by vincent       #+#    #+#                 */
/*   Updated: 2024/01/14 18:20:11 by vincent       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(1 * sizeof(char));
	if (line == NULL)
		return (NULL);
	line = read_stuff(fd, line, buffer, line);
	if (line == NULL)
		return (NULL);
	copy_paste(buffer, &buffer[find_newl(buffer) + 1]);
	if (*line == '\0')
		return (free(line), NULL);
	return (line);
}