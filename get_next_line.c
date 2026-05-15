/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:11:23 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/15 14:53:21 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_next_line_logic(int fd)
{
	char	*buff;
	char	*str;
	int		reading;

	reading = 1;
	str = "";
	while (reading && !ft_strchr(str, '\n'))
	{
		reading = read(fd, buff, BUFFER_SIZE);
		str = ft_strlcat(str, buff);
	}
}

char *get_next_line(int fd)
{
	if (fd < 1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	
}
