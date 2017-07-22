/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 17:01:06 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 17:35:56 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char			*check_other_color(char *str)
{
	if (!(ft_strcmp(str, "LIGHT_YELLOW")))
		return (LIGHT_YELLOW);
	else if (!(ft_strcmp(str, "LIGHT_BLUE")))
		return (LIGHT_BLUE);
	else if (!(ft_strcmp(str, "LIGHT_MAGENTA")))
		return (LIGHT_MAGENTA);
	else if (!(ft_strcmp(str, "LIGHT_CYAN")))
		return (LIGHT_CYAN);
	return (NULL);
}

char				*is_color(char *str)
{
	str = put_maj(str);
	if (!(ft_strcmp(str, "RED")))
		return (RED);
	else if (!(ft_strcmp(str, "GREEN")))
		return (GREEN);
	else if (!(ft_strcmp(str, "YELLOW")))
		return (YELLOW);
	else if (!(ft_strcmp(str, "BLUE")))
		return (BLUE);
	else if (!(ft_strcmp(str, "MAGENTA")))
		return (MAGENTA);
	else if (!(ft_strcmp(str, "CYAN")))
		return (CYAN);
	else if (!(ft_strcmp(str, "LIGHT_GRAY")))
		return (LIGHT_GRAY);
	else if (!(ft_strcmp(str, "DARK_GRAY")))
		return (DARK_GRAY);
	else if (!(ft_strcmp(str, "LIGHT_RED")))
		return (LIGHT_RED);
	else if (!(ft_strcmp(str, "LIGHT_GREEN")))
		return (LIGHT_GREEN);
	else
		return (check_other_color(str));
}
