/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_interne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:58:28 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/11 22:30:57 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		exec_interne(char *cmd, char **params, t_list *list)
{
	(void)cmd;
	(void)list;
	if (ft_strcmp(params[0], "echo") == 0)
		ft_echo(params);
}
