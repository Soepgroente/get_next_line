/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vincent <vincent@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 17:31:07 by vincent       #+#    #+#                 */
/*   Updated: 2024/01/14 18:31:00 by vincent       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newl(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

size_t	get_length(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	copy_paste(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*combine_strings(char *str1, char *str2)
{
	char	*str3;
	size_t	i;

	i = get_length(str1);
	str3 = malloc((i + get_length(str2) + 1) * sizeof(char));
	if (str3 == NULL)
		return (NULL);
	copy_paste(str3, str1);
	copy_paste(&str3[i], str2);
	return (str3);
}
