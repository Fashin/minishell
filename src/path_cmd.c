/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:02:14 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/11 18:45:26 by cbeauvoi         ###   ########.fr       */
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
		if (access(ft_strjoin(tmp[i], cmd), F_OK) == 0)
			return (ft_strjoin(tmp[i], cmd));
	return (NULL);
}
