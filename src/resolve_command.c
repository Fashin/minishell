/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:52:50 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/19 23:23:27 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*check_real_cmd(char **cmds, t_list *list)
{
	int			i;
	char		*tmp;
	char		**auth_cmd;

	i = -1;
	auth_cmd = ft_strsplit(BUILTINS, ';');
	if (ft_arraychr(auth_cmd, cmds[0]))
		return (ft_strjoin("./src/", cmds[0]));
	else if ((tmp = path_cmd(get_value(list, "PATH"), cmds[0])) != NULL)
		return (tmp);
	else
	{
		cmds[0] = ft_strjoin(NF_CMD, cmds[0]);
		return (NULL);
	}
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
		if (ft_arraychr(ft_strsplit(BUILTINS, ';'), cmds[0]))
			return (exec_interne(cmds, list));
		else
			execute_cmd(ret, cmds, list);
	}
	ft_strdel(&ret);
	return (list);
}
