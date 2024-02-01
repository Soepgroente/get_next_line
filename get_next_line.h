/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vincent@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 17:29:13 by vincent       #+#    #+#                 */
/*   Updated: 2024/01/31 17:50:31 by vvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define NOT_FOUND -1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

typedef struct s_data
{
	char	*line;
	size_t	size;
	size_t	len;
}	t_data;

char	*combine_strings(t_data *data, char *str1, char *str2);
void	copy_paste(char *dest, char *src);
int		find_newl(char *str);
char	*ft_realloc(char *old, size_t size);
size_t	get_length(char *str);
char	*get_next_line(int fd);

#endif