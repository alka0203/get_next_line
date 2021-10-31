/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:41:25 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/31 15:21:54 by asanthos         ###   ########.fr       */
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
	concat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	m--;
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
	if (!src)
		return (NULL);
	dest = (char *)malloc(ft_strlen(src) + 1);
	m--;
	if (!dest)
	 	return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!s)
		return (0);
	if (len > (unsigned int)ft_strlen(s))
		len = (unsigned int)ft_strlen(s);
	dst = malloc((len + 1) * sizeof(char *));
	m--;
	if (!dst)
		return (0);
	while (start < (unsigned int)ft_strlen(s) && i < len && s[start + i])
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		boop;
	int		len;
	char	*sub;

	sub = (char *)malloc((ft_strlen(s1) - ft_strlen(set)) + 1);
	m--;
	if (!set)
	 	return (0);
	len = ft_strlen(set);
	boop = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[boop]) && len)
	{
		len--;
		boop--;
	}
	sub = ft_substr(s1, 0, boop);
	free(s1);
	m++;
	return (sub);
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*str;

	str = (void *)malloc(nmemb * size);
	m--;
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}