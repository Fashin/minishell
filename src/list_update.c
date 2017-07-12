/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/12 20:12:40 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		list_update(char *name, char *new_value, t_list **list)
{
	t_env		*env;
	t_list		**tmp;

	(void)new_value;
	tmp = list;
	while ((*tmp)->content)
	{
		env = (t_env *)(*tmp)->content;
		if (ft_strcmp(env->name, name) == 0)
			list_remove(tmp, list);
		(*tmp) = (*tmp)->next;
	}
}
