/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 22:59:54 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/19 22:21:59 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*set_env(char **params, t_list *list)
{
	int			i;
	char		**ret;
	t_env		*env;

	i = -1;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	while (params[++i])
	{
		ret = ft_strsplit(params[i], '=');
		if (ret[0] && ret[1])
		{
			env->name = ft_strdup(ret[0]);
			env->value = ft_strdup(ret[1]);
			ft_lstadd(&list, ft_lstnew((void *)env, sizeof(t_env) * 2));
		}
	}
	return (list);
}
