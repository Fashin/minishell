/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/26 20:36:45 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*list_update(char *name, char *new_value, t_list *list)
{
	t_env		*env;

	list_remove(&list, name);
	if (list)
	{
		if (!(env = (t_env *)ft_memalloc(sizeof(*env))))
			return (NULL);
		env->name = ft_strdup(name);
		env->value = ft_strdup(new_value);
		ft_lstadd(&list, ft_lstnew((void *)env, sizeof(*env)));
		free(env);
	}
	return (list);
}
