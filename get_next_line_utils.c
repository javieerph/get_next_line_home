/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejavier- <ejavier-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:34:16 by ejavier-          #+#    #+#             */
/*   Updated: 2025/05/03 10:15:08 by ejavier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(char *file_name, void *buffer, unsigned bytes)
{
	void *str;
	int	readed;
	int	file;

	str = malloc(bytes * sizeof(char));
	file = open(file_name, "r");
	if (file == -1)
	{
		write(1,"Error opening file",18);
		exit(1);
	}
	else
	{
		readed = read(file_name, str, bytes);
	}
	while (str)
	{
		write(1, &str, 1);
		str++;	
	}
	write(1, "\n", 1);
	close(file_name);
	free(str);
}


