/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:11:23 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/17 20:28:29 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_nline(char *buff)
{
	char	*nstr;
	int		i;

	nstr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!nstr)
		return (NULL);
	while (*buff && *buff != '\n')
		buff++;
	i = 0;
	while (buff[++i])
		nstr[i - 1] = buff[i];
	nstr[i] = 0;
	return (nstr);
}

char	*extract_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] !='\n')
	{
		*line++ = str[i];
		i++;
	}
	line = str[i];
	return (line - i);
}

char	*join_and_free(char *s1, char *s2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

char	*read_eol(int fd, char *buff)
{
	char	*str;
	int		rd_bytes;

	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	rd_bytes = 1;
	str = join_and_free(str, buff);
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
	static char	*str;
	char		*line;
	char		*buff;

	if (fd < 1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, str, ft_strlen(str));
	str = read_eol(fd, buff);
	if (!str)
		return (NULL);
	line = extract_line(str);
	str = extract_nline(buff);
	free(buff);
	return (line);
}	
