/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:21:49 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/13 21:56:28 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char			*clean_spaces(char *str, t_list *list)
{
	int		i;

	if (!(str))
		return (get_value(list, "HOME"));
	i = -1;
	while (str[++i])
		if (ft_isalpha(str[i]) || str[i] == '.' || str[i] == '/')
			return (str + i);
	return (get_value(list, "HOME"));
}

t_list				*ft_cd(char **params, t_list **list)
{
	char		buff[BUFFPATH];
	char		*tmp;
	char		*error;

	(*list) = list_update("OLDPWD", getcwd(buff, BUFFPATH - 1), (*list));
	error = ft_strjoin("cb_sh : no such file or directory: ", params[1]);
	tmp = clean_spaces(params[1], (*list));
	if (chdir(tmp) < 0)
		puterror(0, error);
	(*list) = list_update("PWD", getcwd(buff, BUFFPATH - 1), (*list));
	return ((*list));
}
