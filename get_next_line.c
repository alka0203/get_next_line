/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:40:47 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/24 20:06:44 by asanthos         ###   ########.fr       */
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
	char *temp;

	temp = (char *)malloc(BUFFER_SIZE);
	if (!nextline)
		return (NULL);
	while (checkbreak(buff) == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == '\n' || size == '\0')
		{
			*nextline = '\0';
			nextline = ft_substr(ft_strjoin(nextline, buff), *nextline, ft_strlen(buff));
			//return (nextline);
			break;
		}
		else
			checkbreak(buff);
		*buff = '\0';
		free(buff);
	}
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