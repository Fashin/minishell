/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:37:39 by cbeauvoi          #+#    #+#             */
/*   Updated: 2016/12/10 13:58:49 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int size)
{
	char	*save;

	if (!(save = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	ft_memcpy((void *)save, (void *)str, ft_strlen(str));
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_memcpy((void *)save, (void *)str, ft_strlen(str));
	free(save);
	return (str);
}
