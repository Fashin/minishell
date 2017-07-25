/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:12:45 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 23:45:44 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*list_remove(t_list *list, char *name)
{
	t_list		*ret;
	t_list		*tmp;
	t_env		*env;

	ret = ft_lstnew(NULL, 0);
	while (list->content)
	{
		env = (t_env *)list->content;
		if (ft_strcmp(env->name, name))
		{
			ft_lstadd(&ret, ft_lstnew((void *)env, sizeof(*env)));
		}
		list = list->next;
	}
	return (ret);
}
