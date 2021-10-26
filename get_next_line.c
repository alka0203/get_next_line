/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:40:47 by asanthos          #+#    #+#             */
/*   Updated: 2021/10/26 03:50:28 by asanthos         ###   ########.fr       */
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

	i = 1;
	while (str[i] <= '\n')
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
  int i;
  i = 0;
  if (str[i] == '\0')
    return (0);
  if (ft_strchr(str, '\n'))
    return (1);
  while (i < BUFFER_SIZE)
  {
		ft_strchr(str, '\0');
		return (1);
    	i++;     
  }
  return (0);
  }

char *get_next_line(int fd)
{

	static char	*str;
	int size;
    char buff[BUFFER_SIZE + 1];
	char *store;
	char *nextline;
	
	size = 1;
	if (!str)
		store = "";
	else
		store = ft_strdup(str);
//	if (fd < 0 || (read(fd, buff, BUFFER_SIZE) == -1))
//		return (NULL);
	while (size != 0 && ft_strchr(store, '\n') == 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		buff[size]= '\0';
		store = ft_strjoin(store, buff);
		//if (checkbreak(store) == 1)
			//return (store);
			//break;
    }
	printf("buff = %s\n", buff);
	printf("store = %s\n", store);
	printf("naw we just printing");
	str = ft_strchr(store, '\n');
	nextline = gnl_strcpy(str);
	//if (ft_strlen(str) == 0)
	//	return (NULL);
	free (store);
	return (nextline);
}

int	main(void)
{
	int openfd;
	char *s;	
	openfd = open("file.txt", O_RDONLY);
	s = get_next_line(openfd);
	while (s)
	{
		printf("%s", s);
		s = get_next_line(openfd);
	}
}