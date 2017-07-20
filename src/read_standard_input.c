/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 21:05:20 by cbeauvoi          #+#    #+#             */
/*   Updated: 2017/07/20 21:17:48 by cbeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*read_standard_input(void)
{
	char		*ret;
	
	printf("%d\n", get_next_line(0, &ret));
	return (ret);
}
