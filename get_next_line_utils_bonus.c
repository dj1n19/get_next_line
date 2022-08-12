/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:27:39 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/15 14:28:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (*str++)
		len++;
	return (len);
}

int	ft_find_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == 10)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcat(char *line, char *buffer)
{
	int		line_len;
	int		buffer_len;
	char	*new;
	char	*save;
	char	*line_save;

	line_len = ft_strlen(line);
	buffer_len = ft_strlen(buffer);
	if (line_len > 0)
		line_save = line;
	else
		line_save = NULL;
	new = (char *) malloc(sizeof(char) * (line_len + buffer_len + 1));
	if (!new)
		return (NULL);
	save = new;
	while (line && *line)
		*new++ = *line++;
	while (buffer && *buffer)
		*new++ = *buffer++;
	*new = 0;
	if (line_save)
		free(line_save);
	return (save);
}

char	*ft_ncpy(char *str, int n, int start, int need_free)
{
	char	*new;
	char	*save_new;
	char	*save_str;

	if (ft_strlen(str) == 0)
		return (NULL);
	if (n <= 0)
	{
		free(str);
		return (NULL);
	}
	save_str = str;
	new = (char *) malloc(sizeof(char) * (n + 1));
	if (!new)
		return (NULL);
	save_new = new;
	while (*str && start--)
		str++;
	while (*str && n--)
		*new++ = *str++;
	*new = 0;
	if (need_free == 1)
		free(save_str);
	return (save_new);
}
