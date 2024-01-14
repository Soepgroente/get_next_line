/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vincent@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 17:29:13 by vincent       #+#    #+#                 */
/*   Updated: 2024/01/14 18:15:15 by vincent       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10
# define NOT_FOUND -1

char	*combine_strings(char *str1, char *str2);
void	copy_paste(char *dest, char *src);
int		find_newl(char *str);
size_t	get_length(char *str);

#endif