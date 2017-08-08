/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:42:12 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/08 22:40:47 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*get_value(t_list *list, char *name)
{
	t_env		*env;

	while (list->content)
	{
		env = (t_env *)list->content;
		if (env && env->name && name)
			if (!(ft_strcmp(env->name, name)))
				return (env->value);
		list = list->next;
	}
	return (NULL);
}
