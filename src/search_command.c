/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:05:59 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/23 22:03:27 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char			*clean_up_tabs(char *str)
{
	int			i;
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

static char			**clean_back_line(char **str)
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

t_list				*search_command(char *cmd, t_list *list)
{
	char	**tmp;
	char	**ret;
	int		i;

	clean_up_tabs(cmd);
	ret = NULL;
	if (ft_strstr(cmd, ";"))
	{
		i = -1;
		tmp = ft_strsplit(cmd, ';');
		while (tmp[++i])
		{
			ret = clean_back_line(ft_strsplit(tmp[i], ' '));
			list = resolve_command(ret, list);
		}
		free_tab(tmp);
		free_tab(ret);
	}
	else
		list = resolve_command(clean_back_line(ft_strsplit(cmd, ' ')), list);
	ft_strclr(cmd);
	return (list);
}
