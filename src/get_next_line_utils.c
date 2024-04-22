/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:42:11 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/28 18:40:02 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_isnewline(char *str, int flag)
{
	size_t	index;

	if (str == 0)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index++] == '\n')
			return (index);
	}
	if (flag)
		return (0);
	else
		return (index);
}

char	*ft_makebuffer(char **buffer)
{
	size_t	index;
	char	*result;

	if (*buffer)
		return (*buffer);
	index = 0;
	result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (result == 0)
		return (0);
	while (index <= BUFFER_SIZE)
		result[index++] = 0;
	return (result);
}

void	*ft_makefree(char **str)
{
	free(*str);
	return (0);
}

char	*ft_strlinedup(char *buffer, ssize_t length, ssize_t *index, int *flag)
{
	size_t	res_index;
	size_t	res_size;
	char	*result;

	if (buffer == 0 || length < 0)
		return (0);
	if (*index >= length)
		return (0);
	res_index = 0;
	res_size = ft_isnewline(&buffer[*index], 0);
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	if (result == 0)
	{
		*flag = 1;
		return (0);
	}
	while (res_index < res_size)
		result[res_index++] = buffer[(*index)++];
	result[res_index] = 0;
	return (result);
}

char	*ft_strfreecat(char	**dst, char	*buffer, ssize_t length, ssize_t *index)
{
	size_t	res_size;
	size_t	dst_size;
	size_t	res_index;
	size_t	tmp_index;
	char	*result;

	if (length == 0)
		return (*dst);
	if (length < 0)
		return (ft_makefree(dst));
	res_index = 0;
	tmp_index = 0;
	dst_size = ft_isnewline(*dst, 0);
	res_size = dst_size + ft_isnewline(buffer, 0);
	result = (char *)malloc(sizeof(char) * (res_size + 1));
	while (result && tmp_index < dst_size)
		result[res_index++] = (*dst)[tmp_index++];
	while (result && res_index < res_size)
		result[res_index++] = buffer[(*index)++];
	if (result)
		result[res_index] = 0;
	if (*dst)
		free(*dst);
	return (result);
}
