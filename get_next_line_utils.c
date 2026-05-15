/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:13:30 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/15 19:14:59 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (char)c != *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*point;
	int		i;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	point = malloc(size * nmemb);
	if (!point)
		return (NULL);
	while (size * nmemb--)
		((char *)point)[i++] = 0;
	return (point);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	index;

	index = 0;
	count = ft_strlen(src);
	if (size == 0)
		return (count);
	while (src[index] && index < (size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*point;
	size_t	size;		

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	point = ft_calloc(size + 1, sizeof(char));
	if (!point)
		return (NULL);
	ft_strlcpy(point, s1, ft_strlen(s1) + 1);
	ft_strlcpy(point + ft_strlen(s1), s2, ft_strlen(s2));
	return (point);
}
