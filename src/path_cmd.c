/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:02:14 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/26 18:24:48 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*path_cmd(char *path, char *cmd)
{
	int		i;
	char	**tmp;
	char	*ret;

	i = -1;
	tmp = ft_strsplit(path, ':');
	cmd = ft_strjoin("/", cmd);
	ret = NULL;
	while (tmp[++i])
		if (access(tmp[i] = ft_strjoin(tmp[i], cmd), F_OK) == 0)
		{
			ft_strdel(&cmd);
			ret = ft_strdup(tmp[i]);
			free_tab(tmp);
			return (ret);
		}
	free_tab(tmp);
	return (NULL);
}
