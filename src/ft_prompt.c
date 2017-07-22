/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:51:13 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 17:47:28 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*prompt_color = NULL;

void		ft_prompt(void)
{
	(!(prompt_color)) ? ft_putstr(LIGHT_GRAY) : ft_putstr(prompt_color);
	ft_putstr("$ > ");
	ft_putstr(LIGHT_GRAY);
}

void			set_params(char *str, int interne)
{
	char		**params;

	params = ft_strsplit(str, '=');
	if (params[0] && params[1])
	{
		if (!(ft_strcmp(params[0], "set-prompt-color")))
			if (!(prompt_color = is_color(params[1])))
				ft_putstr(ft_strjoin(RED, NF_COLOR));
	}
	else if (interne)
		if (!(prompt_color = is_color(str)))
			ft_putstr(ft_strjoin(RED, NF_COLOR));
	free_tab(params);
}

void		set_prompt(char **av)
{
	int		i;

	i = 0;
	while (av[++i])
		if (av[i][0] == '-' && av[i][1] == '-')
			set_params(av[i] + 2, 0);
}
