/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:11:23 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/16 14:13:54 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *str)
{
	int		i;
	char	*line;

	line = "";
	i = 0;
	while (str[i] && str[i] !='\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*join_and_free(char *s1, char *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	*read_eol(int fd)
{
	char	*buff;
	char	*str;
	int		rd_bytes;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	rd_bytes = 1;
	while (rd_bytes && !ft_strchr(str, '\n'))
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		str = join_and_free(str, buff);
	}
	return (str);
}

char *get_next_line(int fd)
{
	static char *str;
	char *line;

	if (fd < 1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	str = read_eol(fd);
	if (!str)
		return (NULL);
	line = extract_line(str);
	str = ft_strchr(str, '\n');
	return (line);
}	
