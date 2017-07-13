/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 18:38:34 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*list_update(char *name, char *new_value, t_list *list)
{
	t_env		*env;

	list = list_remove(list, name);
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (list)
	{
		env->name = ft_strdup(name);
		env->value = ft_strdup(new_value);
		ft_lstadd(&list, ft_lstnew((void *)env, sizeof(t_env) * 2));
	}
	return (list);
}
