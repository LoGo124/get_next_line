/* ************************************************************************** */
/*                                                                            */

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
		printf("Res: %s\n---\n", str);
		while (ft_strlen(str) > 43)
		{
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
