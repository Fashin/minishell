/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:17:56 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 18:15:56 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			save_env(char **env, t_list **list)
{
	int			i;
	char		**tmp;
	t_env		*set_env;

	i = -1;
	if (!(set_env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	while (env[++i])
	{
		tmp = ft_strsplit(env[i], '=');
		set_env->name = ft_strdup(tmp[0]);
		set_env->value = ft_strdup(tmp[1]);
		ft_lstadd(list, ft_lstnew((void *)set_env, sizeof(t_env) * 2));
	}
	return (1);
}
