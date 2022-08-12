/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:27:14 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/15 14:34:27 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_read(int fd, char **lines)
{
	char	buffer[BUFFER_SIZE + 1];
	int		res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (res == -1 || res == 0)
		return (res);
	buffer[res] = 0;
	lines[fd] = ft_strcat(lines[fd], buffer);
	return (res);
}

static char	*ft_make_line(char **lines, int fd, int index)
{
	char	*line;

	line = ft_ncpy(lines[fd], index + 1, 0, 0);
	lines[fd] = ft_ncpy(lines[fd],
			ft_strlen(lines[fd]) - index - 1, index + 1, 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*lines[OPEN_MAX];
	int			index;
	int			res;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	index = ft_find_nl(lines[fd]);
	while (index == -1)
	{
		res = ft_read(fd, lines);
		if (res == -1)
			return (NULL);
		if (res == 0 && ft_strlen(lines[fd]) == 0)
			return (NULL);
		if (res == 0)
			return (ft_make_line(lines, fd, ft_strlen(lines[fd])));
		index = ft_find_nl(lines[fd]);
	}
	return (ft_make_line(lines, fd, index));
}
