/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:49:22 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/28 17:55:43 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fdlist	*head;
	t_fdlist		*current;
	char			*result;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (0);
	current = ft_find_lst(fd, &head);
	if (current == 0)
		return (0);
	result = 0;
	while (current->buf_length > 0)
	{
		result = ft_make_str(&result, &current, &head);
		if (head == 0 || current->res_flag)
			return (result);
		current->buf_length = read(fd, current->buffer, BUFFER_SIZE);
		current->buf_index = 0;
	}
	if (current->buf_length < 0 && result)
	{
		free(result);
		result = 0;
	}
	ft_remove_lst(fd, &head, 0);
	return (result);
}
