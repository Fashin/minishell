/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:53:50 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/29 19:44:43 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list			*ft_cpyenv(t_list *list)
{
	t_list		*new_list;
	t_env		env;

	if (!(new_list = ft_lstnew(NULL, 0)))
		exit(-1);
	while (list->content)
	{
		env.name = ft_strdup(((t_env *)list->content)->name);
		env.value = ft_strdup(((t_env *)list->content)->value);
		ft_lstadd(&new_list, ft_lstnew((void *)&env, sizeof(t_env)));
		list = list->next;
	}
	return (new_list);
}
