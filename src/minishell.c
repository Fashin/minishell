/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:12:49 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/19 23:17:11 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					main(int ac, char **av, char **env)
{
	char		*cmd;
	t_list		*list;

	(void)ac;
	(void)av;
	list = ft_lstnew(NULL, 0);
	if (!(save_env(env, &list)))
		puterror(1, "Error from allocation memory");
	while (1)
	{
		ft_putstr("$ > ");
		cmd = read_standard_input();
		list = resolve_command(search_command(cmd), list);
	}
	return (0);
}
