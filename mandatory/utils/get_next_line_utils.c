/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:31:40 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/11/16 21:31:41 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (s);
	if ((unsigned char )c == 0)
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (*(s + (++i)))
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}

char	*set_read_line(char *line)
{
	char	*str;
	int		i;

	i = 0;
	if (*line == 0)
		return (NULL);
	while (*(line + i) && *(line + i) != '\n')
		i++;
	if (*(line + i) == '\n')
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (str);
	i = 0;
	while (*(line + i) && *(line + i) != '\n')
	{
		str[i] = *(line + i);
		i++;
	}
	if (*(line + i) == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*set_next_line(char *line)
{
	char	*str;
	int		j;
	int		i;

	i = 0;
	while (*(line + i) && *(line + i) != '\n')
		i++;
	if (*(line + i) == '\0')
		return (free(line), NULL);
	str = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (str);
	i++;
	j = 0;
	while (*(line + i))
	{
		str[j] = *(line + i);
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(line), str);
}
