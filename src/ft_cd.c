/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:21:49 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/22 14:19:36 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list				*ft_cd(char **params, t_list **list)
{
	char		buff[BUFFPATH];
	char		*tmp;
	int		freed;

	freed = 0;
	tmp = (!(params[1])) ? get_value(*list, "HOME") : convert_special_char(params[1], *list, &freed);
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
	if (freed)
		ft_strdel(&tmp);
	return ((*list));
}
