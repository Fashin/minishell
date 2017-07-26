/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:34:26 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/26 22:03:02 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void				free_tab(char **params)
{
	int		i;

	i = -1;
	if (!(params))
		return ;
	while (params[++i])
		ft_strdel(&(params[i]));
	ft_memdel((void **)&params);
}

void				free_env(void *content, size_t size)
{
	t_env		**p;

	p = (t_env **)content;
	if (p != NULL || *p != NULL)
		free(*p);
	*p = NULL;
	size = 0;
}

void				free_lst(t_list **list)
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = *list;
	while (tmp->content)
	{
		tmp2 = tmp;
		tmp = tmp2->next;
		ft_strdel(&(((t_env *)tmp2->content)->name));
		ft_strdel(&(((t_env *)tmp2->content)->value));
		free(tmp2);
	}
}

void				ft_exit(char **params, t_list *list, int stop)
{
	if (params)
		free_tab(params);
	if (list)
		ft_lstdel(&list, &free_env);
	if (stop)
	{
		ft_putstr_fd("Good Bye ! :)\n", 0);
		exit(1);
	}
}
