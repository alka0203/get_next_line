/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:40:47 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/24 16:31:04 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i++;
	}
	if (c == '\0')
		return (&((char *)str)[i]);
	return (0);
}

static	int	ft_len(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (12);
	if (n == 0)
		return (2);
	while (n < 0 || n == 0)
	{
		n *= -1;
		i++;
	}
	while (n != '\0')
	{
		n /= 10;
		i++;
	}
	return (i);
}

//return 1 if new line is being returned
int	checkbreak(char *str)
{
	if (ft_strchr(str, '\n') || ft_strchr(str, '\0'))
		return (1);
	return (0);
}

char *get_next_line(int fd)
{
	static char	*nextline;
	int size;
    char buff[BUFFER_SIZE + 1];

	if (!nextline ||  size < 0)
		return (NULL);
	while (checkbreak(buff) == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size >= 0)
		{
			//nextline = ft_substr(buff, *nextline, checkbreak(buff));
			nextline = ft_strjoin(nextline, buff);
			return (nextline);
		}
	}
	*nextline = '\0';
	return (nextline);
}

int	main(void)
{
	int openfd;
	char *s;

	openfd = open("file.txt", O_RDONLY);
	//while (get_next_line(openfd))
	//{
	//	printf("%s", get_next_line(openfd));
	//}
	s = get_next_line(openfd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(openfd);
	}
}