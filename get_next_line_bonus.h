/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:47:43 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/28 17:02:20 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_fdlist
{
	int				fd;
	char			*buffer;
	ssize_t			buf_length;
	ssize_t			buf_index;
	size_t			res_length;
	size_t			res_index;
	size_t			res_old_index;
	int				res_flag;
	struct s_fdlist	*next;
}				t_fdlist;

char		*get_next_line(int fd);
size_t		ft_get_size(t_fdlist *lst);
char		*ft_make_str(char **str, t_fdlist **lst, t_fdlist **head);
void		ft_remove_lst(int fd, t_fdlist **head, int flag);
t_fdlist	*ft_make_lst(int fd);
t_fdlist	*ft_find_lst(int fd, t_fdlist **head);

#endif
