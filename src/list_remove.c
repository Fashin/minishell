/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:12:45 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/22 14:52:22 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int			check_first_maillon(t_list **list, char *name)
{
	t_env	*env;
	t_list	*tmp;

	env = ((t_env *)(*list)->content);
	if (!(ft_strcmp(env->name, name)))
	{
		tmp = *list;
		*list = (*list)->next;
		ft_lstdelone(&tmp, &free_env);
		return (1);
	}
	return (0);
}

void				list_remove(t_list **list, char *name)
{
	t_list		*tmp;
	t_list		*del;
	t_env		*env;

	del = NULL;
	if (check_first_maillon(list, name))
		return ;
	tmp = *list;
	while (tmp->content)
	{
		if (tmp->next->content)
		{
			env = (t_env *)tmp->next->content;
			if (!(ft_strcmp(env->name, name)))
			{
				del = tmp->next;
				tmp->next = tmp->next->next;
			}
		}
		tmp = tmp->next;
	}
	if (del)
		ft_lstdelone(&del, &free_env);
}
