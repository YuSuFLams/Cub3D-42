/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:40:04 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/08 14:38:06 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_atoi(const char *s)
{
	int	sign;
	int	n;

	sign = 1;
	n = 0;
	while (*s && (*s == 32 || (*s >= 9 && *s <= 13)))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= (-1);
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
		n = n * 10 + *s++ - '0';
	return (n * sign);
}