/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:21:49 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/25 23:29:02 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list				*ft_cd(char **params, t_list **list)
{
	char		buff[BUFFPATH];
	char		*tmp;

	tmp = (!(params[1])) ? get_value(*list, "HOME") : convert_special_char(params[1], *list);
	if (!(tmp))
		puterror(0, NF_ENV);
	else
	{
		getcwd(buff, BUFFPATH - 1);
		if (chdir(tmp) < 0)
			puterror(0, ft_strjoin(NF_FILE, tmp));
		(*list) = list_update("OLDPWD", buff, (*list));
		ft_strclr(buff);
		(*list) = list_update("PWD", getcwd(buff, BUFFPATH - 1), (*list));
	}
	ft_strdel(&tmp);
	return ((*list));
}
