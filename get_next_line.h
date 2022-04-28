/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:13:25 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/28 16:12:50 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_line_lst
{
	char				*line;
	int					fd;
	struct s_line_lst	*next;
}				t_line_lst;

t_line_lst	*ft_new(char *line, int fd);
char		*ft_get_line(t_line_lst *line_lst, int fd);
t_line_lst	*ft_add_line(t_line_lst *line_lst, char *line, int fd);
void		ft_free_lst(t_line_lst *line_lst);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_read(int fd);
t_line_lst	*ft_find_line(int fd, t_line_lst *line_lst);
char		*get_next_line(int fd);

#endif
