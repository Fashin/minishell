/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 17:57:32 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/11 17:58:55 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*get_path(t_list *list)
{
	t_env		*get_env;

	while (list->content)
	{
		get_env = (t_env *)list->content;
		if (ft_strcmp(get_env->name, "PATH") == 0)
			return (get_env->value);
		list = list->next;
	}
	return (NULL);
}
