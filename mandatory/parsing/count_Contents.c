/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_Contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 00:29:07 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/16 00:55:16 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_dir_fl(char *s)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (*(s + i))
	{
		while (is_space(*(s + i)) && *(s + i))
			i++;
		if (*(s + i))
			counter++;
		while (!is_space(*(s + i)) && *(s + i))
			i++;
	}
	return (counter);
}

int	check_array_is_full(t_cub3d *vars)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!vars->direction[i])
			return (1);
	i = -1;
	while (++i < 2)
		if (!vars->floor[i])
			return (2);
	return (0);
}

char	*first_word(char *s)
{
	int		i;
	int		j;
	char	*f_str;

	if (!s)
		return (s);
	f_str = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!f_str)
		return (NULL);
	i = 0;
	while (*(s + i) && ((*(s + i) >= 9 && *(s + i) <= 13) || *(s + i) == 32))
		i++;
	j = 0;
	while (*(s + i) && !(*(s + i) >= 9 && *(s + i) <= 13) && *(s + i) != 32)
		*(f_str + j++) = *(s + i++);
	*(f_str + j) = '\0';
	return (f_str);
}

char	*last_word(char *s)
{
	int		i;
	int		j;
	char	*f_str;

	if (!s)
		return (s);
	f_str = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!f_str)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (*(s + i) && ((*(s + i) >= 9 && *(s + i) <= 13) || *(s + i) == 32))
		i--;
	while (*(s + i) && !(*(s + i) >= 9 && *(s + i) <= 13) && *(s + i) != 32)
		i--;
	i++;
	j = 0;
	while (*(s + i) && !(*(s + i) >= 9 && *(s + i) <= 13) && *(s + i) != 32)
		*(f_str + j++) = *(s + i++);
	*(f_str + j) = '\0';
	return (f_str);
}

int	count_number_colors(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ',' && str[i])
			i++;
		if (str[i] != ',' && str[i])
			count++;
		while (str[i] != ',' && str[i])
			i++;
	}
	return (count);
}
