/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:01:24 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/15 14:25:51 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd;

	while (ac > 0)
	{
		fd = open(av[ac--], O_RDONLY);
		printf("Resultado: %s\n", get_next_line(fd));
	}
}
