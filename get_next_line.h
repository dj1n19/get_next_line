/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:30:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/22 17:27:35 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# elif BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# elif BUFFER_SIZE >= 262144
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 262143
# endif
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_find_nl(char *buffer);
char	*ft_strcat(char *line, char *buffer);
char	*ft_ncpy(char *str, int n, int start, int need_free);

#endif
