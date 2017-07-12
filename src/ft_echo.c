/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:17:10 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/11 22:32:06 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		ft_echo(char **params)
{
	int		i;
	char	back_line;

	i = 0;
	back_line = '\n';
	while (params[++i])
	{
		if (i == 1 && (ft_strcmp(params[1], "-n") == 0))
			back_line = '\0';
		else
		{
			ft_putstr_fd(params[i], 0);
			if (params[i + 1])
				ft_putchar_fd(' ', 0);
		}
	}
	ft_putchar_fd(back_line, 0);
}
