/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pers_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:01:53 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 22:04:42 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		check_start(char *str)
{
	if ((str[0] == '/')
		|| (str[0] == '.' && str[1] == '/')
		|| (str[0] == '.' && str[1] == '.' && str[2] == '/'))
		return (1);
	return (0);
}

char			*check_pers_cmd(char *path)
{
	struct stat sb;

	if (!(check_start(path)))
		return (NULL);
	if (access(path, F_OK) == 0)
		if (stat(path, &sb) == 0
			&& !(sb.st_mode & S_IFDIR)
			&& (sb.st_mode & S_IXUSR))
			return (path);
	return (NULL);
}
