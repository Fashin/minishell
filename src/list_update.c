/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/08 22:40:09 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*list_update(char *name, char *new_value, t_list *list)
{
	t_list		*new;

	list_remove(&list, name);
	if (!(new = (t_list *)ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->content = (void *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	((t_env *)new->content)->name = ft_strdup(name);
	((t_env *)new->content)->value = ft_strdup(new_value);
	new->next = NULL;
	ft_lstadd(&list, new);
	return (list);
}
