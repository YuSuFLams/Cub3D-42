/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:34:04 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 16:06:09 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count(char const *s, char c)
{
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

void	freesplit(char **s, int i)
{
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	j = 0;
	n = -1;
	if (!s)
		exit(EXIT_FAILURE);
	str = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!str)
		exit(EXIT_FAILURE);
	while (++n < count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[n] = ft_substr(s, j, i - j);
		if (!str[n])
			(freesplit(str, 0), exit(EXIT_FAILURE));
	}
	return (str[n] = NULL, str);
}
