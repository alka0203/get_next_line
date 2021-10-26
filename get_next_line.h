/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:41:14 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/25 23:57:45 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 12
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char *gnl_strcpy(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*get_next_line(int fd);
int	    checkbreak(char *str);
int	    ft_strlen(char const *str);

#endif
