/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:41:25 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/26 03:06:19 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (0);
	concat = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!concat)
		return (0);
	while (s1[i])
	{
		((char *)concat)[i] = ((char *)s1)[i];
		i++;
	}
	while (s2[j])
	{
		((char *)concat)[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

char	*ft_strdup(char const *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i++] = '\0';
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	unsigned int	i;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

/*size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (src[j] && j + 1 < dstsize)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize)
		dst[j] = '\0';
	return (i + 1);
}*/

char *gnl_strcpy(char *src)
{
	int	i;
	char *dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(src));
	while (src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}