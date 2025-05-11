/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:44:45 by ejavier-          #+#    #+#             */
/*   Updated: 2025/05/11 09:42:32 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *buffer, char *buf);
char	*read_file(int fd, char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src,
			size_t destsize);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}

char	*ft_joinfree(char *buffer, char *buf)
{
	char	*join;

	join = ft_strjoin(buffer, buf);
	free(buffer);
	return (join);
}

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		byte_numb;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_numb = 1;
	while (byte_numb > 0)
	{
		byte_numb = read(fd, buffer, BUFFER_SIZE);
		if (byte_numb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_numb] = '\0';
		str = ft_joinfree(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, const char *src,
	size_t destsize)
{
	size_t	destlen;
	size_t	srclen;
	size_t	bytes;
	size_t	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destsize <= destlen)
		return (srclen + destsize);
	bytes = destsize - destlen - 1;
	i = 0;
	while (src[i] != '\0' && i < bytes)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
#include <stdio.h>
int main(void)
{
	char buffer[] = "Hola, Edgar!\n¿Cómo estás?\nEspero que bien.";
	char *next_line = ft_next(buffer);

	printf("%s", next_line); // Salida: "¿Cómo estás?\nEspero que bien."

	free(next_line); // Liberar memoria después de usarlo
	return (0);
}
