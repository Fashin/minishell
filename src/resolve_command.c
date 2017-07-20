/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:52:50 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/20 22:17:18 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*check_real_cmd(char **cmds, t_list *list)
{
	char		*ret;
	char		**auth_cmd;

	auth_cmd = ft_strsplit(BUILTINS, ';');
	if ((ret = ft_arraychr(auth_cmd, cmds[0])))
		cmds[0] = ft_strjoin("ft_", cmds[0]);
	ret = (!(ret)) ? path_cmd(get_value(list, "PATH"), cmds[0]) : ret;
	if (!(ret))
		cmds[0] = ft_strjoin(NF_CMD, cmds[0]);
	free_tab(auth_cmd);
	return (ret);
}

static int		execute_cmd(char *cmd, char **params, t_list *list)
{
	pid_t		pid;
	int			status;

	pid = fork();
	status = 0;
	if (!pid)
		execve(cmd, params, convert_env(list));
	else if (pid > 0)
		waitpid(pid, &status, 0);
	return (status);
}

t_list			*resolve_command(char **cmds, t_list *list)
{
	char	*ret;

	ret = check_real_cmd(cmds, list);
	if (!(ret))
		puterror(0, cmds[0]);
	else
	{
		printf("asked cmd = %s\n", cmds[0]);
		if (ft_strnstr(cmds[0], "ft_", 3))
			return (exec_interne(cmds, list));
		else
			execute_cmd(ret, cmds, list);
	}
	ft_strdel(&ret);
	return (list);
}
