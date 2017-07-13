/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:59:54 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 23:04:20 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*set_env(char **params, t_list *list)
{
	int			i;
	char		**ret;
	t_env		*env;

	(void)list;
	i = -1;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	while (params[++i])
	{
		ret = ft_strsplit(params[i], '=');
	}
	return (list);
}
