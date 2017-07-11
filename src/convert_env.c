/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:00:22 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/11 21:07:09 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t		sizeof_list(t_list *list)
{
	size_t		length;

	length = 0;
	while (list->content)
	{
		length++;
		list = list->next;
	}
	return (length);
}

static char			*convert_equals(char *name, char *value)
{
	char		*ret;

	ret = ft_strjoin(name, "=");
	ret = ft_strjoin(ret, value);
	return (ret);
}

char				**convert_env(t_list *list)
{
	char		**ret;
	int			i;
	t_env		*env;
	size_t		lst_length;

	lst_length = sizeof_list(list);
	if (!(ret = (char **)malloc(sizeof(char *) * lst_length)))
		return (NULL);
	i = -1;
	while (list->content)
	{
		env = (t_env *)list->content;
		lst_length = ft_strlen(env->value) + ft_strlen(env->name);
		if (!(ret[++i] = (char *)malloc(sizeof(char) * lst_length)))
			return (NULL);
		ret[i] = convert_equals(env->name, env->value);
		list = list->next;
	}
	return (ret);
}
