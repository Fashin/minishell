/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:05:59 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 16:43:58 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*clean_up_tabs(char *str)
{
	int		i;
	size_t		length;
	char		*tmp;

	length = ft_strlen(str) + 1;
	i = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	ft_bzero(tmp, length);
	while (str[++i])
		tmp[i] = (str[i] == '\t') ? ' ' : str[i];
	ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}

static char		**clean_back_line(char **str)
{
	int			i;
	size_t		length;

	i = -1;
	while (str[++i])
	{
		length = ft_strlen(str[i]);
		if (str[i][length - 1] == '\n')
			str[i] = ft_strncpy(ft_strnew(length), str[i], length - 1);
	}
	return (str);
}

char			**search_command(char *cmd)
{
	char	**ret;

	ret = NULL;
	clean_up_tabs(cmd);
	ret = ft_strsplit(cmd, ' ');
	ret = clean_back_line(ret);
	ft_strclr(cmd);
	return (ret);
}
