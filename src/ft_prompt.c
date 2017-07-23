/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:51:13 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/23 22:17:50 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list				*ft_prompt(t_list *list)
{
	char		*buff;
	char		*ret;
	
	buff = ft_strnew(sizeof(*buff));
	ret = get_value(list, "COLOR");
	if (!(ret))
		list = list_update("COLOR", "LIGHT_GRAY", list);
	ft_putstr(get_color(get_value(list, "COLOR"), &buff));
	ft_putstr("$ > ");
	ft_putstr("\e[37m");
	ft_strdel(&buff);
	ft_strdel(&ret);
	return (list);
}

static t_list		*save_interne_color(char *str, char *ret, t_list *list)
{
	get_color(put_maj(str), &ret);
	if (!(ret))
		ft_putstr(ft_strjoin("\e[93m", NF_COLOR));
	else
		list = list_update("COLOR", ret, list);
	ft_putstr("\e[37m");
	return (list);
}

t_list				*set_params(char *str, int interne, t_list *list)
{
	char		**params;
	char		*ret;

	params = ft_strsplit(str, '=');
	ret = ft_strnew(sizeof(*ret));
	if (params[0] && params[1])
	{
		if (!(ft_strcmp(params[0], "set-prompt-color")))
		{
			get_color(put_maj(params[1]), &ret);
			if (!(ret))
				ft_putstr(ft_strjoin("\e[93m", NF_COLOR));
			else
				list = list_update("COLOR", ret, list);
		}
	}
	if (interne)
		list = save_interne_color(str, ret, list);
	free_tab(params);
	return (list);
}

t_list				*set_prompt(char **av, t_list *list)
{
	int		i;

	i = 0;
	while (av[++i])
		if (av[i][0] == '-' && av[i][1] == '-')
			list = set_params(av[i] + 2, 0, list);
	return (list);
}
