/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:59:54 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 18:53:54 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*set_env(char **params, t_list *list)
{
	int			i;
	char		**ret;

	i = -1;
	while (params[++i])
	{
		ret = ft_strsplit(params[i], '=');
		if (ret[0] && ret[1])
			list = list_update(ret[0], ret[1], list);
		free_tab(ret);
	}
	return (list);
}
