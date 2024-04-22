/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:23:54 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/10 18:33:33 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	static ssize_t	length;
	static ssize_t	buf_index;
	int				free_flag;
	char			*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	free_flag = 0;
	result = ft_strlinedup(buffer, length, &buf_index, &free_flag);
	buffer = ft_makebuffer(&buffer);
	while (buffer && !(free_flag) && !(ft_isnewline(result, 1)))
	{
		if (buf_index >= length)
			buf_index = 0;
		length = read(fd, buffer, BUFFER_SIZE);
		if (length > 0)
			buffer[length] = 0;
		result = ft_strfreecat(&result, buffer, length, &buf_index);
		if (result == 0 || length <= 0)
			free_flag = 1;
	}
	if (free_flag && !(result))
		buffer = ft_makefree(&buffer);
	return (result);
}
