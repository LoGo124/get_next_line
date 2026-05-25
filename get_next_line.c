/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:11:23 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/25 13:44:34 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_nline(char *buff)
{
	char	*nstr;
	int		i;
	int		j;

	nstr = malloc(BUFFER_SIZE + 1  * sizeof(char));
	if (!nstr)
	{
		//free(buff);
		return (NULL);
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(nstr);
		free(buff);
		return(NULL);
	}
	j = -1;
	while (buff[i + ++j + 1])
		nstr[j] = buff[i + j + 1];
	nstr[j] = 0;
	free(buff);
	return (nstr);
}

char	*extract_line(char *buff)
{
	char	*line;

	if (!buff || !*buff)
		return(NULL);
	line = ft_strdup(buff);
	if (ft_strchr(buff, '\n'))
		line[(int)(ft_strchr(buff, '\n') - buff) + 1] = 0;
	else
		line[ft_strlen(line)] = 0;
	return (line);
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
	char	*buffer;
	int		rd_bytes;

	if (!buff)
		buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	rd_bytes = 1;
	while (rd_bytes > 0 && !ft_strchr(buff, '\n'))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			buff = NULL;
		else if (rd_bytes > 0)
		{
			buffer[rd_bytes] = 0;
			buff = join_and_free(buff, buffer);
		}
	}
	free(buffer);
	return (buff);
}

char *get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	char		*readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	readed = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!readed)
	{
		free(buff);
		return (NULL);
	}
	if (!buff)
	{
		buff = ft_strdup("");
		readed[0] = 0;
	}
	else
		readed = ft_strdup(buff);
	free(buff);
	readed = read_eol(fd, readed);
	if (!readed)
		return (NULL);
	line = extract_line(readed);
	buff = extract_nline(readed);
	if (!buff)	
		free(buff);
	return (line);
}
