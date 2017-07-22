/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:34:26 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 21:57:27 by cbeauvoi         ###   ########.fr       */
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
		ft_strdel(&params[i]);
	ft_memdel((void **)&params);
}

void				free_lst(t_list *list)
{
	t_list		*tmp;

	tmp = list;
	while (list->content)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void				free_super_tab(char ***tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free_tab(tab[i]);
	tab = NULL;
}

void				ft_exit(char **params, t_list *list, int stop)
{
	if (params)
		free_tab(params);
	if (list)
		free_lst(list);
	if (stop)
	{
		ft_putstr_fd("Good Bye ! :)\n", 0);
		exit(1);
	}
}
