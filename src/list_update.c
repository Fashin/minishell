/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/02 22:31:27 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*list_update(char *name, char *new_value, t_list *list)
{
	t_env		*env;

	list_remove(&list, name);
	printf("remove %s\n", name);
	env = NULL;
	if (list)
	{
		if (!(env = (t_env *)ft_memalloc(sizeof(*env))))
			return (NULL);
		env->name = name;
		env->value = new_value;
		ft_lstadd(&list, ft_lstnew((void *)env, sizeof(*env)));
		free(env);
		printf("[%s] = %s has been added\n", name, new_value);
	}
	return (list);
}
