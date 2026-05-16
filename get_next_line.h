/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilopez-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:14:00 by ilopez-g          #+#    #+#             */
/*   Updated: 2026/05/16 14:11:01 by ilopez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// get_next_line
char	*get_next_line(int fd);
char    *read_eol(int fd);
char    *join_and_free(char *s1, char *s2);
char    *extract_line(char *str);
// get_next_line_utils
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
void    *ft_calloc(size_t nmemb, size_t size);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);

#endif
