/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <ilopez-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:35:09 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/25 13:08:54 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*str;

	while (--ac)
	{
		fd = open(av[ac], O_RDONLY);
		str = get_next_line(fd);
		printf("Res: %s\n---\n", str);
		while (str && ft_strlen(str) > 43)
		{
			free(str);
			str = get_next_line(fd);
			printf("Res: %s\n---\n", str);
		}
		//str = get_next_line(fd);
		//printf("\nResultado: %s<\n", str);
	}
	free(str);
	close(fd);
	return (0);
}
