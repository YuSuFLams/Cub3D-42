/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:35:04 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/24 16:12:04 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	is_space(char c)
{
	if (c == '\t' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

bool	is_all_space(char *line)
{
	int	i;

	i = 0;
	while (*(line + i))
	{
		if (!is_space(*(line + i)))
			return (false);
		i++;
	}
	return (true);
}
