/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:02:14 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 23:43:34 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*path_cmd(char *path, char *cmd)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = ft_strsplit(path, ':');
	cmd = ft_strjoin("/", cmd);
	while (tmp[++i])
		if (access(tmp[i] = ft_strjoin(tmp[i], cmd), F_OK) == 0)
		{
			ft_strdel(&cmd);
			return (tmp[i]);
		}
	free_tab(tmp);
	return (NULL);
}
