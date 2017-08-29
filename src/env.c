/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 19:05:18 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/29 19:54:14 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				print_env(t_list *list)
{
	t_env			*env;

	while (list->content)
	{
		env = (t_env *)list->content;
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putendl(env->value);
		list = list->next;
	}
}

static t_list		*insert_exec_new_env(char **params, t_list *list)
{
	char		**data;

	data = ft_strsplit(params[1], '=');
	if (data[0] && data[1])
	{
		list = list_update(data[0], data[1], list);
		if (!(params[2]))
			print_env(list);
		else
			list = resolve_command(params + 2, list, 0);
	}
	free_tab(&data);
	return (list);
}

t_list				*env(char **params, t_list *list)
{
	t_list		*tmp;

	if (!(params[1]))
		print_env(list);
	else
	{
		if (!(tmp = ft_cpyenv(list)))
			exit(-1);
		tmp = insert_exec_new_env(params, tmp);
		ft_lstdel(&tmp, &free_env);
	}
	return (list);
}
