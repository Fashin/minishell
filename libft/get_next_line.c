/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:21:33 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/23 23:03:25 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char			*clean_back(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		if (str[i] != '\n')
			str[i] = str[i];
	return (str);
}

static int			get_input(int fd, char **line)
{
	char		buff[BUFF_SIZE];
	int			stop;

	stop = 0;
	if (!(*line = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	ft_bzero(buff, BUFF_SIZE);
	while ((read(fd, buff, BUFF_SIZE - 1)) > 0)
	{
		if (ft_strchr(buff, '\n') || ft_strchr(buff, '\0'))
			stop = 1;
		*line = (!(*line)) ? buff : ft_strjoin(*line, clean_back(buff));
		ft_bzero(buff, BUFF_SIZE);
		if (stop)
			return (1);
		else
			*line = ft_realloc(*line, BUFF_SIZE - 1);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	if (fd >= 0)
		return (get_input(fd, line));
	return (1);
}
