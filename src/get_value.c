/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:42:12 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/08/08 22:40:47 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*contain_special_char(char *str, t_list *list)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '~')
			return (get_value(list, "HOME"));
		else if (str[i] == '-')
			return (get_value(list, "OLDPWD"));
	return (NULL);
}

char		*convert_special_char(char *str, t_list *list, int *freed)
{
	char	*tmp;

	if (!(tmp = contain_special_char(str, list)))
		return (str);
	*freed = 1; 
	return (ft_strjoin(tmp, str + 1));
}

char		*get_value(t_list *list, char *name)
{
	t_env		*env;

	while (list->content)
	{
		env = (t_env *)list->content;
		if (env && env->name && name)
			if (!(ft_strcmp(env->name, name)))
				return (env->value);
		list = list->next;
	}
	return (NULL);
}
