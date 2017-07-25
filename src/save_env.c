/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:17:56 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 18:54:15 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			create_my_env(t_list **list)
{
	t_env		*env;

	ft_putstr(ft_strjoin("\e[93m", W_ENV));
	if (!(env = (t_env *)ft_memalloc(sizeof(*env))))
		return (0);
	env->name = "PATH";
	env->value = "./src/";
	ft_lstadd(list, ft_lstnew((void *)env, sizeof(*env)));
	free(env);
	return (1);
}

int					save_env(char **env, t_list **list)
{
	int			i;
	char		**tmp;
	t_env		*set_env;

	if (!(env[0]))
		return (create_my_env(list));
	i = -1;
	while (env[++i])
	{
		if (!(set_env = (t_env *)ft_memalloc(sizeof(*set_env))))
			return (0);
		tmp = ft_strsplit(env[i], '=');
		set_env->name = ft_strdup(tmp[0]);
		set_env->value = ft_strdup(tmp[1]);
		ft_lstadd(list, ft_lstnew((void *)set_env, sizeof(*set_env)));
		free_tab(tmp);
		free(set_env);
	}
	return (1);
}
