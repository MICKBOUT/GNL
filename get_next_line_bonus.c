/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:51:37 by mboutte           #+#    #+#             */
/*   Updated: 2025/11/18 22:56:31 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find(char *buffer)
{
	int i;

	i = -1;
	while (buffer[++i])
		if (buffer[i] == '\n')
			return (i);
	return (-1);
}
void	ft_remove_start(char *buffer, int to_remove)
{
	//set the first part of the buffer to buffer + to remove
	//set the last part of the buffer to '\0'
}

char	*ft_add_left(char output, char *buffer, char *left)
{
	//add the buffer to the output check if output NULL
	//ft_remove_start in the buffer
}

char	*get_next_line(int fd)
{
	static char	buffer[16][BUFFER_SIZE + 1];
	int			byte_read;
	char		*output;
	
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	output = NULL;
		//if newline in buffer :
	// return a part of the buffer and cut the part in the buffer
	//read in the file
	while (byte_read > 0)
	{
//		add the buffer up to the end or a new line in the output, and remove the part in the buffer
//      if newline at the end of the output
//			return the output
//      read in the file
	}
	// if read == -1
	// return NULL
	return (output);
}
