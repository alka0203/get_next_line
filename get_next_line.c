/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asanthos <asanthos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:40:47 by asanthos          #+#    #+#             */
/*   Updated: 2021/11/01 01:16:23 by asanthos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

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

char	*fd_nextline(char *str, char *store)
{
	char	*nextline;

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
		nextline = ft_substr(store, 0, (ft_strlen(store) - ft_strlen(str)));
		free (store);
	}
	if (ft_strlen(nextline) == 0)
		return (NULL);
	return (nextline);
}

char	*fd_store(char *str, char *store)
{
	if (!str)
		store = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	else
	{
		store = ft_strdup(str);
		free (str);
	}
	return (store);
}

void	initialize(int *size, char **store)
{
	*size = 1;
	*store = "";
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			size;
	char		*store;
	char		buff[BUFFER_SIZE + 1];

	initialize(&size, &store);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = fd_store(str, store);
	while ((ft_strchr(store, '\n') == 0) && (size != 0))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(store);
			return (NULL);
		}
		str = ft_strdup(store);
		free (store);
		buff[size] = '\0';
		store = ft_strjoin(str, buff);
		free (str);
	}
	str = ft_strdup(ft_strchr(store, '\n'));
	return (fd_nextline(str, store));
}
