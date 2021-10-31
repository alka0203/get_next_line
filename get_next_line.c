/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:40:47 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/31 14:29:02 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

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

int	ft_strlen(char const *str)
{
	int		i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&((char *)str)[i + 1]);
		i++;
	}
	if (c == '\0')
		return (&((char *)str)[i]);
	return (0);
}

// char	*storeValues(char *store, char	*str)
// {
// 	store = (char *)malloc((BUFFER_SIZE + 1));
//     if (!str)
//         store = "";
//     else
//         store = ft_strdup(str);
// 	return (store);
// }

char	*get_next_line(int fd)
{
    static char	*str;
    int size;
    char buff[BUFFER_SIZE + 1];
    char *store;
    char *nextline;
    
    size = 1;
    if (!str)
	{
        store = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		m--;
	}
    else
	{
        store = ft_strdup(str);
		free (str);
	}
	//store = storeValues(store, str);
    while ((ft_strchr(store, '\n') == 0) && (size != 0))
    {
		str = ft_strdup(store);
		free (store);
		m++;
        size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		buff[size] = '\0';
        store = ft_strjoin(str, buff);
		free (str);
		m++;
	}
	//printf("store=%s\n", store);
	str = ft_strdup(ft_strchr(store, '\n'));
	//printf("str=%s\n", str);
	if (ft_strlen(str) == 0)
	{
		if (ft_strlen(store) == 0)
		{
			free (store);
			return (NULL);
		}
		else
		{
	 		nextline = ft_strdup(store);
			free (store);
		}
	}
	else
	{
		nextline = ft_strtrim(store, str);
	}
	if (ft_strlen(nextline) == 0)
		return (0);
	//free (store);
	m++;
    return (nextline);
}

//#include "./get_next_line_utils.c"

int main(void)
{
    int openfd;
    char *s;

    //openfd = open("gnlTester/files/empty", O_RDONLY); 
	openfd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
    //openfd = open("file.txt", O_RDONLY);
    s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
    s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
    s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
    s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
    s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
	s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
	s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
	s = get_next_line(openfd);
    printf("%s", s);
    free (s); m++;
}