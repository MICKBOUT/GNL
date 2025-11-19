/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:51:37 by mboutte           #+#    #+#             */
/*   Updated: 2025/11/19 12:30:39 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_remove_start(char *buffer, int to_remove)
{
	int	i;

	i = 0;
	while (buffer[i + to_remove])
	{
		buffer[i] = buffer[i + to_remove];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_creat_string(char *output, char *buffer, char *new)
{
	int	i;
	int	j;

	i = 0;
	if (output)
	{
		while (output[i])
		{
			new[i] = output[i];
			i++;
		}
		free(output);
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		new[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		new[i + j++] = '\n';
	new[i + j] = '\0';
	ft_remove_start(buffer, j);
	return (new);
}

char	*ft_add_left(char *output, char *buffer)
{
	char	*new;
	int		size;

	size = ft_find(buffer);
	if (size == -1)
		size = ft_strlen(buffer);
	new = malloc(sizeof(char) * (ft_strlen(output) + size + 2));
	if (!new)
		return (NULL);
	return (ft_creat_string(output, buffer, new));
}

char	*get_next_line(int fd)
{
	static char	buffer[16][BUFFER_SIZE + 1];
	char		*output;
	int			byte_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	output = NULL;
	if (ft_find(buffer[fd]) > -1)
		return (ft_add_left(output, buffer[fd]));
	if (buffer[fd][0] != '\0')
		output = ft_add_left(output, buffer[fd]);
	byte_read = read(fd, buffer[fd], BUFFER_SIZE);
	while (byte_read > 0)
	{
		buffer[fd][byte_read] = '\0';
		output = ft_add_left(output, buffer[fd]);
		if (ft_find(output) > -1)
			return (output);
		byte_read = read(fd, buffer[fd], BUFFER_SIZE);
	}
	if (byte_read == -1)
		return (NULL);
	return (output);
}
