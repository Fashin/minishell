/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 23:09:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/26 19:39:17 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*unset_env(char **params, t_list *list)
{
	int		i;

	i = -1;
	while (params[++i])
		list_remove(&list, params[i]);
	return (list);
}
