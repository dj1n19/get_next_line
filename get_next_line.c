/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:15:57 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/23 17:15:40 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*join;

	size = 0;
	i++;
	while (s1[i++])
		size++;
	i = 0;
	while (s2[i++])
		size++;
	join = (char *) malloc(sizeof(char) * size + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = 0;
	free(s1);
	free(s2);
	return (join);
}

char	*ft_read(int fd)
{
	int		res;
	int		i;
	char	*buffer;

	i = 0;
	res = 1;
	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i < BUFFER_SIZE && res != 0)
	{
		res = read(fd, buffer[i], 1);
		i++;
		if (buffer[i - 1] == 10)
			break;
	}
	if (buffer[i - 1] != 10 && res != 0)
		buffer = ft_strjoin(buffer, ft_read(fd));
	buffer[i] = 0;
	return (buffer);
}

void	*ft_find_line(int fd, t_line_lst *line_lst)
{
	char	*buffer;

	buffer = ft_read(fd);
	ft_add_line(line_lst, buffer, fd);
}

char	*get_next_line(int fd)
{
	static t_line_lst	*line_lst;

	if (fd < 0)
		return (NULL);
	ft_find_line(fd, line_lst);
	return (ft_get_line(line_lst, fd));
}
