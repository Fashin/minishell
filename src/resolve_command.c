/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 16:52:50 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 22:56:36 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*check_real_cmd(char **cmds, t_list *list, char **error)
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
		(*error) = ft_strjoin("cb_sh : command not found : ", cmds[0]);
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
	char	*error;

	error = NULL;
	ret = check_real_cmd(cmds, list, &error);
	if (error)
		puterror(0, error);
	else
	{
		if (ft_arraychr(ft_strsplit(BUILTINS, ';'), cmds[0]))
			return (exec_interne(cmds[0], cmds, list));
		else
			execute_cmd(ret, cmds, list);
	}
	return (list);
}
