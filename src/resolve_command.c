/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:52:50 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/08 20:15:45 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char			*check_real_cmd(char **cmds, t_list *list, int *intern)
{
	char		*ret;
	char		**auth_cmd;

	auth_cmd = ft_strsplit(BUILTINS, ';');
	if ((ret = ft_arraychr(auth_cmd, cmds[0])))
		*intern = 1;
	ret = (!(ret)) ? path_cmd(get_value(list, "PATH"), cmds[0]) : ret;
	ret = (!(ret)) ? check_pers_cmd(cmds[0], intern) : ret;
	if (!(ret))
		cmds[0] = ft_strjoin(NF_CMD, cmds[0]);
	free_tab(&auth_cmd);
	return (ret);
}

static int			execute_cmd(char *cmd, char **params, t_list *list)
{
	pid_t		pid;
	int			status;

	pid = fork();
	status = 0;
	if (pid > 0)
		waitpid(pid, &status, 0);
	if (pid == 0)
		execve(cmd, params, convert_env(list));
	kill(pid, SIGTERM);
	return (status);
}

t_list				*resolve_command(char **cmds, t_list *list, int clean)
{
	char	*ret;
	int		intern;

	intern = 0;
	ret = check_real_cmd(cmds, list, &intern);
	if (!(ret))
		puterror(0, cmds[0]);
	else
	{
		if (intern == 1)
			list = exec_interne(cmds, list);
		else
			execute_cmd(ret, cmds, list);
	}
	if (!(intern))
		ft_strdel(&ret);
	if (clean && intern != 2)
		free_tab(&cmds);
	return (list);
}
