/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:01:06 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/22 14:12:37 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char				*get_color(char *name, char **ret)
{
	char	colors[16][2][13] = {
		{"RED", "\e[31m"},
		{"GREEN", "\e[32m"},
		{"YELLOW", "\e[33m"},
		{"BLUE", "\e[34m"},
		{"MAGENTA", "\e[35m"},
		{"CYAN", "\e[36m"},
		{"LIGHT_GRAY", "\e[37m"},
		{"LIGHT_RED", "\e[91m"},
		{"LIGHT_GREEN", "\e[92m"},
		{"LIGHT_YELLOW", "\e[93m"},
		{"LIGHT_BLUE", "\e[94m"},
		{"LIGHT_CYAN", "\e[96m"},
	};
	int		i;

	i = -1;
	while (++i < 15)
		if (!(ft_strcmp(colors[i][0], name))
			&& ((*ret) = ft_strdup(colors[i][0])) != NULL)
			return (ft_strdup(colors[i][1]));
	(*ret) = NULL;
	return ("\e[37m");
}
