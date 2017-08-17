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

static char	*insert_env_var(char *tmp, t_list *list, char *value, int *j)
{
	char		*ret;
	
	ret = get_value(list, value);
	if (!(ret))
		return (NULL);
	tmp = ft_realloc((void *)tmp, ft_strlen(ret) - 1);
	tmp = ft_strcpy(tmp, ret);
	*j += ft_strlen(ret) - 1;
	return (tmp);
}

char		*convert_special_char(char *str, t_list *list)
{
	int	i;
	int	j;
	char	*tmp;

	i = -1;
	j = -1;
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) - 1))))
		return (NULL);
	j = 0;
	while (str[++i])
	{
		if (str[i] == '~')
			tmp = insert_env_var(tmp, list, "HOME", &j);
		else if (str[i] == '-')
			tmp = insert_env_var(tmp, list, "OLDPWD", &j);
		else
			tmp[j + i] = str[i];
		if (!(tmp))
			return (NULL);
	}
	//tmp[j + i] = '\0';
	return (tmp);
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
