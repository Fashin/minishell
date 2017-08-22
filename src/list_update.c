/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:41 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/08 22:46:03 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*list_update(char *name, char *new_value, t_list *list)
{
	t_list		*new;

	list_remove(&list, name);
	if (!(new = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = (void *)ft_memalloc(sizeof(*env))))
		return (NULL);
	((t_env *)new->content)->name = ft_strnew(ft_strlen(name));
	((t_env *)new->content)->value = ft_strnew(ft_strlen(new_value));
	((t_env *)new->content)->name = ft_strcpy(((t_env *)list->content)->name, name);
	((t_env *)new->content)->value = ft_strcpy(((t_env *)list->content)->value, new_value);
	new->next = NULL;
	ft_lstadd(&list, new);
	return (list);
}
