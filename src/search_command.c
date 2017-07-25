/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:05:59 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 23:25:23 by cbeauvoi         ###   ########.fr       */
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
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * length)))
		return (NULL);
	ft_bzero(tmp, length);
	while (str[++i])
		tmp[i] = (str[i] == '\t') ? ' ' : str[i];
	str = ft_strcpy(str, tmp);
	free(tmp);
	return (str);
}

t_list				*search_command(char *cmd, t_list *list)
{
	char	**tmp;
	int		i;

	clean_up_tabs(cmd);
	if (ft_strchr(cmd, ';'))
	{
		i = -1;
		tmp = ft_strsplit(cmd, ';');
		while (tmp[++i])
			list = resolve_command(ft_strsplit(tmp[i], ' '), list);
		free_tab(tmp);
	}
	else
		list = resolve_command(ft_strsplit(cmd, ' '), list);
	ft_strclr(cmd);
	return (list);
}
