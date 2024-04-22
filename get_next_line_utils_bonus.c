/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:47:36 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/28 17:15:22 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_get_size(t_fdlist *lst)
{
	ssize_t	index;
	int		null_index;
	char	*str;
	ssize_t	length;
	ssize_t	start;

	lst->res_flag = 0;
	null_index = 0;
	index = 0;
	str = lst->buffer;
	length = lst->buf_length;
	start = lst->buf_index;
	if (length > 0 && lst->res_length == 0 && length - start > 0)
		null_index = 1;
	while (start + index < length)
	{
		if (str[start + index++] == '\n')
		{
			lst->res_flag = 1;
			break ;
		}
	}
	return (index + null_index);
}

char	*ft_make_str(char **str, t_fdlist **lst, t_fdlist **head)
{
	char	*result;
	size_t	str_size;

	result = 0;
	str_size = (*lst)->res_index;
	(*lst)->res_length += ft_get_size(*lst);
	if ((*lst)->res_length)
		result = (char *)malloc(sizeof(char) * (*lst)->res_length);
	if (result == 0 && (*lst)->res_length)
	{
		ft_remove_lst(-1, head, 1);
		free(*str);
		return (0);
	}
	(*lst)->res_index = 0;
	(*lst)->res_old_index = 0;
	while (*str && (*lst)->res_old_index < str_size && result)
		result[(*lst)->res_index++] = (*str)[(*lst)->res_old_index++];
	if (*str)
		free(*str);
	while ((*lst)->res_index + 1 < (*lst)->res_length && result)
		result[(*lst)->res_index++] = (*lst)->buffer[(*lst)->buf_index++];
	if (result)
		result[(*lst)->res_index] = 0;
	return (result);
}

void	ft_remove_lst(int fd, t_fdlist **head, int flag)
{
	t_fdlist	*body;
	t_fdlist	*tail;

	tail = *head;
	while (tail)
	{
		if (tail->fd == fd && !flag)
			break ;
		body = tail;
		tail = tail->next;
		if (flag)
		{
			free(body->buffer);
			free(body);
			*head = 0;
		}
	}
	if (*head == 0)
		return ;
	free(tail->buffer);
	if (tail != *head)
		body->next = tail->next;
	else
		*head = (*head)->next;
	free(tail);
}

t_fdlist	*ft_make_lst(int fd)
{
	t_fdlist	*lst;

	lst = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (lst == 0)
		return (0);
	lst->buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (lst->buffer == 0)
	{
		free(lst);
		return (0);
	}
	lst->fd = fd;
	lst->buffer[0] = 0;
	lst->buf_length = 1;
	lst->buf_index = 1;
	lst->res_length = 0;
	lst->res_index = 0;
	lst->res_old_index = 0;
	lst->res_flag = 0;
	lst->next = 0;
	return (lst);
}

t_fdlist	*ft_find_lst(int fd, t_fdlist **head)
{
	t_fdlist	*body;
	t_fdlist	*tail;

	if (*head == 0)
		*head = ft_make_lst(fd);
	if (*head == 0)
		return (0);
	tail = *head;
	while (tail)
	{
		tail->res_index = 0;
		tail->res_length = 0;
		if (tail->fd == fd)
			return (tail);
		body = tail;
		tail = tail->next;
	}
	body->next = ft_make_lst(fd);
	if (body->next == 0)
	{
		ft_remove_lst(-1, head, 1);
		return (0);
	}
	return (body->next);
}
