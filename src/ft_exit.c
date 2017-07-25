/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:34:26 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 19:22:52 by cbeauvoi         ###   ########.fr       */
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
		ft_strdel((&params[i]));
	ft_memdel((void **)&params);
}

void				free_env(void *content, size_t size)
{

	size = 0;
	ft_strdel(&((t_env *)content)->name);
	free(content);
}

void				free_lst(t_list *list)
{
	t_list		*tmp;

	while (list->content)
	{
		tmp = list;
		list = tmp->next;
		ft_memdel(&(list->content));
		free(tmp);
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
