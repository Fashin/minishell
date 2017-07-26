/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:05:18 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/26 21:55:15 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list				*print_env(t_list *list)
{
	t_env			*env;
	t_list			*tmp;

	tmp = list;
	while (tmp->content)
	{
		env = (t_env *)tmp->content;
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->value);
		tmp = tmp->next;
	}
	//free_lst(&tmp);
	return (list);
}

static void			insert_exec_new_env(char **params, t_list *list)
{
	char		**data;

	data = ft_strsplit(params[1], '=');
	if (data[0] && data[1])
	{
		list_update(data[0], data[1], list);
		if (!(params[2]))
			print_env(list);
		else
			resolve_command(params + 2, list);
	}
}

t_list				*env(char **params, t_list **list)
{
	if (!(params[1]))
		return (print_env((*list)));
	else
		insert_exec_new_env(params, (*list));
	return ((*list));
}
