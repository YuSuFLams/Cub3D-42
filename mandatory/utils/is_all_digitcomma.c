/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_digitcomma.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:23:55 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/08 14:36:10 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_comma(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	while (*(s + (++i)))
		if (*(s + i) == ',')
			count++;
	return (count);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	digitcomma(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != ',' && !ft_isdigit(*(s + i)))
			return (0);
		i++;
	}
	return (1);
}
