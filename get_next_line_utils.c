/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:49:24 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/23 16:47:44 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line_lst	*ft_new(char *line, int fd)
{
	t_line_lst	*new;

	new = (t_line_lst *) malloc(sizeof(t_line_lst));
	if (!new)
		return (NULL);
	new->line = line;
	new->fd = fd;
	new->next = NULL;
	return (new);
}

char	*ft_get_line(t_line_lst *line_lst, int fd)
{
	while (line_lst->fd != fd && line_lst)
		line_lst = line_lst->next;
	return (line_lst->line);
}

t_line_lst	*ft_add_line(t_line_lst *line_lst, char *line, int fd)
{
	while (line_lst->next)
		line_lst = line_lst->next;
	line_lst->next = ft_new(line, fd);
	return (line_lst->next);
}

void	ft_free_lst(t_line_lst *line_lst)
{
	t_line_lst	*tmp;

	while (line_lst)
	{
		tmp = line_lst;
		line_lst = line_lst->next;
		free(tmp->line);
		free(tmp);
	}
}
