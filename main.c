/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:01:24 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/16 20:24:59 by ilopez-g         ###   ########.fr       */
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
		printf("\nResultado: %s<\n", str);
		//str = get_next_line(fd);
		//printf("\nResultado: %s<\n", str);
	}
	free(str);
	return (0);
}
