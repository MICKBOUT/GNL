/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:51:37 by mboutte           #+#    #+#             */
/*   Updated: 2025/11/18 16:51:28 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_left(int byte_read, char *buffer, int *len, char *left)
{
	char	*dest;
	int		i;
	int		j;

	if (byte_read + *len < 0)
		return (NULL);
	dest = malloc(sizeof(char) * (byte_read + *len));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < *len)
		dest[i] = left[i];
	j = -1;
	while (++j < byte_read)
		dest[i + j] = buffer[j];
	*len = *len + byte_read;
	free(left);
	return (dest);
}

int	ft_find_new(char *left, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (left[i] == '\n')
			return (i);
	return (-1);
}

void	ft_remove_start(char **left, int *len, int to_remove)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * ((*len) - to_remove));
	if (!new)
	{
		*len = 0;
		new = NULL;
	}
	else
	{
		i = -1;
		while (++i < *len - to_remove)
			new[i] = (*left)[i + to_remove];
		*len -= to_remove;
	}
	free(*left);
	*left = new;
}

char	*ft_output(char **left, int *len)
{
	int		size;
	int		i;
	char	*output;

	size = ft_find_new(*left, *len) + 1;
	if (size == 0)
		size = *len;
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = (*left)[i];
		i++;
	}
	output[i] = 0;
	ft_remove_start(left, len, i);
	return (output);
}

char	*get_next_line(int fd)
{
	static char		*left = NULL;
	static int		len = 0;
	static char		*buffer = NULL;
	int				byte_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE);
	while (1)
	{
		if (len > 0 && ft_find_new(left, len) > -1)
			return (ft_output(&left, &len));
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
			return (NULL);
		if (byte_read > 0)
			left = ft_add_left(byte_read, buffer, &len, left);
		if (byte_read <= 0 && len > 0)
			return (ft_output(&left, &len));
		else if (byte_read == 0)
			return (NULL);
	}
}
