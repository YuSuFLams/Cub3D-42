/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:31:18 by ylamsiah          #+#    #+#             */
/*   Updated: 2024/01/03 16:04:21 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*read_line(int fd, char *line)
{
	char	*str;
	int		count;

	str = malloc(BUFFER_SIZE + 1 * sizeof(char ));
	if (!str)
		return (str);
	count = 1;
	while (!ft_strchr(line, '\n') && count != 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count == -1)
			return (free(str), free(line), NULL);
		str[count] = '\0';
		line = ft_strjoin(line, str);
	}
	return (free(str), line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*final;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	final = 0;
	line = read_line(fd, line);
	if (!line)
		exit(EXIT_FAILURE);
	final = set_read_line(line);
	line = set_next_line(line);
	return (final);
}
