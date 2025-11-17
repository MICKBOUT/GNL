/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:51:37 by mboutte           #+#    #+#             */
/*   Updated: 2025/11/17 16:53:23 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_cat(char **text, char *buffer, size_t byte_read)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(*text) + byte_read + 1));
}

char	*get_next_line(int fd, )
{
	static char	*text;
	char		*buffer;
	size_t		byte_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	ft_cat(text, buffer, byte_read);
	free(buffer);
	return ();
}
