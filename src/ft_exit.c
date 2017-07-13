/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:34:26 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 19:42:10 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void			free_tab(char **params)
{
	int		i;

	i = -1;
	while (params[++i])
		ft_strdel(&(params[i]));
	ft_memdel((void **)&params);
}

void				free_lst(t_list *list)
{
	t_list		*tmp;

	while (list->content)
	{
		tmp = list;
		list = list->next;
		ft_strdel(tmp->content);
	}
}

void				ft_exit(char *cmd, char **params, t_list *list, int stop)
{
	ft_strdel(&cmd);
	free_tab(params);
	if (list)
		free_lst(list);
	if (stop)
	{
		ft_putstr_fd("Good Bye ! :)\n", 0);
		exit(1);
	}
}
