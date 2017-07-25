/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:12:49 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 23:42:16 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int					main(int ac, char **av, char **env)
{
	char		*cmd;
	t_list		*list;

	list = ft_lstnew(NULL, 0);
	if (ac > 1)
		list = set_prompt(av, list);
	if (!(save_env(env, &list)))
		puterror(1, "Error from allocation memory");
	while (1)
	{
		ft_prompt(list);
		cmd = NULL;
		get_next_line(0, &cmd);
		if (ft_strcmp(cmd, ""))
			search_command(cmd, list);
		ft_strdel(&cmd);
	}
	return (0);
}
