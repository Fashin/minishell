/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:02:14 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/22 17:41:20 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*path_cmd(char *path, char *cmd)
{
	int		i;
	char	**tmp;
	char	*ret;

	i = -1;
	if (!(path))
		return (NULL);
	tmp = ft_strsplit(path, ':');
	cmd = ft_strjoin("/", cmd);
	ret = NULL;
	while (tmp[++i])
		if (access(tmp[i] = ft_freejoin(tmp[i], cmd), F_OK) == 0)
		{
			ft_strdel(&cmd);
			ret = ft_strdup(tmp[i]);
			free_tab(&tmp);
			return (ret);
		}
	ft_strdel(&cmd);
	free_tab(&tmp);
	return (NULL);
}
