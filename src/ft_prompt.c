/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:51:13 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/22 22:28:00 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list			*ft_prompt(t_list *list)
{
	ft_putstr(get_value(list, "COLOR"));
	ft_putstr("$ > ");
	ft_putstr(LIGHT_GRAY);
	return (list);
}

t_list			*set_params(char *str, int interne, t_list *list)
{
	char		**params;
	char		*ret;

	params = ft_strsplit(str, '=');
	if (params[0] && params[1])
	{
		if (!(ft_strcmp(params[0], "set-prompt-color")))
		{
			if (!(ret = is_color(params[1])))
				ft_putstr(NF_COLOR);	
			else
				list = list_update("COLOR", ret, list);
		}
	}
	else if (interne)
	{
		if (!(ret = is_color(str)))
			ft_putstr(ft_strjoin(RED, NF_COLOR));
		else
			list = list_update("COLOR", ret, list);
	}
	free_tab(params);
	return (list);
}

t_list			*set_prompt(char **av, t_list *list)
{
	int		i;

	i = 0;
	while (av[++i])
		if (av[i][0] == '-' && av[i][1] == '-')
			list = set_params(av[i] + 2, 0, list);
	return (list);
}
