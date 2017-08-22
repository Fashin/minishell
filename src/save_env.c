/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:17:56 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/22 17:32:56 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			create_my_env(t_list **list)
{
	t_env		env;

	ft_putstr(ft_strjoin("\e[93m", W_ENV));
	env.name = ft_strdup("PATH");
	env.value = ft_strdup("./src/");
	ft_lstadd(list, ft_lstnew((void *)&env, sizeof(t_env)));
	return (1);
}

int					save_env(char **env, t_list **list)
{
	int			i;
	char		**tmp;
	t_env		set_env;

	if (!(env[0]))
		return (create_my_env(list));
	i = -1;
	set_env.name = NULL;
	set_env.value = NULL;
	while (env[++i])
	{
		tmp = ft_strsplit(env[i], '=');
		if (!(tmp[0]) || !(tmp[1]))
			puterror(1, ft_strjoin(RED, NF_ENVAL));
		set_env.name = ft_strdup(tmp[0]);
		set_env.value = ft_strdup(tmp[1]);
		if (!(set_env.name) || !(set_env.value))
			return (0);
		ft_lstadd(list, ft_lstnew((void *)&set_env, sizeof(t_env)));
		free_tab(&tmp);
	}
	return (1);
}
