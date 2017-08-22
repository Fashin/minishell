/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:01:06 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/22 15:08:20 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char				*get_color(char *name, char **ret)
{
	if (!(ft_strcmp(name, "RED")) && (*ret = "RED"))
		return (RED);
	else if (!(ft_strcmp(name, "GREEN")) && (*ret = "GREEN"))
		return (GREEN);
	else if (!(ft_strcmp(name, "YELLOW")) && (*ret = "YELLOW"))
		return (YELLOW);
	else if (!(ft_strcmp(name, "BLUE")) && (*ret = "BLUE"))
		return (BLUE);
	else if (!(ft_strcmp(name, "MAGENTA")) && (*ret = "MAGENTA"))
		return (MAGENTA);
	else if (!(ft_strcmp(name, "CYAN")) && (*ret = "CYAN"))
		return (CYAN);
	else if (!(ft_strcmp(name, "LIGHT_GRAY")) && (*ret = "LIGHT_GRAY"))
		return (LIGHT_GRAY);
	else if (!(ft_strcmp(name, "LIGHT_RED")) && (*ret = "LIGHT_RED"))
		return (LIGHT_RED);
	else if (!(ft_strcmp(name, "LIGHT_YELLOW")) && (*ret = "LIGHT_YELLOW"))
		return (LIGHT_YELLOW);
	else if (!(ft_strcmp(name, "LIGHT_BLUE")) && (*ret = "LIGHT_BLUE"))
		return (LIGHT_BLUE);
	else if (!(ft_strcmp(name, "LIGHT_CYAN")) && (*ret = "LIGHT_CYAN"))
		return (LIGHT_CYAN);
	return ("\e[37m");
}

t_list				*set_color(t_list *list, char **ret, char **buff)
{
	list = list_update("COLOR", "LIGHT_GRAY", list);
	*ret = "\e[37m";
	*buff = ft_strdup("LIGHT_GRAY");
	return (list);
}
