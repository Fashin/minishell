/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_interne.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:58:28 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/20 20:55:33 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list		*exec_interne(char **params, t_list *list)
{

	if (ft_strcmp(params[0], "ft_echo") == 0)
		ft_echo(params);
	else if (ft_strcmp(params[0], "ft_exit") == 0)
		ft_exit(params, list, 1);
	else if (ft_strcmp(params[0], "ft_cd") == 0)
		return (ft_cd(params, &list));
	else if (ft_strcmp(params[0], "ft_env") == 0)
		return (env(params, &list));
	else if (ft_strcmp(params[0], "ft_setenv") == 0)
		return (set_env(params + 1, list));
	else if (ft_strcmp(params[0], "ft_unsetenv") == 0)
		return (unset_env(params + 1, list));
	return (list);
}
