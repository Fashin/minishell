/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:05:18 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 22:56:43 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list		*print_env(t_list *list)
{
	t_env		*env;
	t_list		*tmp;

	tmp = list;
	while (tmp->content)
	{
		env = (t_env *)tmp->content;
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->value);
		tmp = tmp->next;
	}
	free_lst(tmp);
	return (list);
}


static void			insert_exec_new_env(char **params, t_list *list)
{
	t_env		*env;
	char		**data;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return ;
	data = ft_strsplit(params[1], '=');
	if (data[0] && data[1])
	{
		env->name = ft_strdup(data[0]);
		env->value = ft_strdup(data[1]);
		ft_lstadd(&list, ft_lstnew((void *)env, sizeof(t_env) * 2));
		if (!(params[2]))
			print_env(list);
		else
			resolve_command(params + 2, list);
	}
}

t_list				*env(char **params, t_list **list)
{
	if (params[1] == NULL)
		return (print_env((*list)));
	else
		insert_exec_new_env(params, (*list));
	return ((*list));
}
