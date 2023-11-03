/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:02:58 by adiaz-uf          #+#    #+#             */
/*   Updated: 2022/11/26 20:01:40 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char	*ft_read_line(char *stash)
{
	int		size;
	char	*s;

	size = 0;
	if (!stash[size])
		return (0);
	while (stash[size] && stash[size] != '\n')
		size++;
	s = malloc(sizeof(char) * (size + 2));
	if (!s)
		return (0);
	size = 0;
	while (stash[size] && stash[size] != '\n')
	{
		s[size] = stash[size];
		size++;
	}
	if (stash[size] == '\n')
	{
		s[size] = stash[size];
		size++;
	}
	s[size] = '\0';
	return (s);
}

static char	*ft_save_stash(char *stash)
{
	int		size;
	int		i;
	char	*s;

	size = 0;
	while (stash[size] && stash[size] != '\n')
		size++;
	if (!stash[size])
	{
		free(stash);
		return (0);
	}
	s = ft_calloc_gnl(sizeof(char), (ft_strlen_g(stash) - size + 1));
	if (!s)
		return (0);
	size++;
	i = 0;
	while (stash[size])
		s[i++] = stash[size++];
	s[i] = '\0';
	free(stash);
	return (s);
}

static char	*ft_read_buffer(int fd, char *stash)
{
	char	*buff;
	int		bytes_readed;

	buff = ft_calloc_gnl(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	bytes_readed = 1;
	while (!ft_strchr_gnl(stash, '\n') && bytes_readed != 0)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed < 0)
		{
			free(stash);
			free(buff);
			return (0);
		}
		buff[bytes_readed] = '\0';
		stash = ft_strjoin_gnl(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line[fd] = ft_read_buffer(fd, next_line[fd]);
	if (!next_line[fd])
		return (0);
	line = ft_read_line(next_line[fd]);
	next_line[fd] = ft_save_stash(next_line[fd]);
	return (line);
}
/*
int main()
{
    int fd;
	char *str;
   
    fd = open("archivo.txt", O_RDONLY);
	printf ("%i", fd);
    while(1)
    {
		
        str = get_next_line(fd);
        if (!str)
            break;
		printf("%s", str);
        free(str);
	}
}*/
