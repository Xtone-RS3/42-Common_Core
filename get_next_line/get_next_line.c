/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:24:48 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/20 11:24:50 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*splitter(char *buffer, int size)
{
	int		i;
	char	*line;

	if (!buffer || size <= 0)
		return (NULL);
	i = 0;
	//if (!buffer[i])//size == 0)
	//	return (NULL);
	line = ft_calloc(size + 1, 1);
	if (!line)
		return (free(buffer), NULL);
	while (i < size && buffer[i])//i != size)
	{
		line[i] = buffer [i];
		i++;
	}
	return (line);
}

char	*remain(char *buffer, int size)
{
	//int		i;
	int		j;
	char	*result;

	if (!buffer || size >= len_count(buffer))
		return (free(buffer), NULL);
	//i = 0;
	j = 0;
	/*while ((size + i - 1) < len_count(buffer) && size != 0)
	{
		printf("workssssssssssss\n");
		i++;
	}*/
	result = ft_calloc(len_count(buffer) - size + 1, 1);
	if (!result)
		return (free(buffer), NULL);
	while (buffer[size])//j < i)// && size < len_count(buffer)
	{
		//printf("remain\n");
		result[j++] = buffer[size++];
	}
	return (free(buffer), result);
}

char	*read_func(int fd, char *buffer)
{
	char	*hold;
	int		bytes_read;

	hold = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		//printf("here\n");
		bytes_read = read(fd, hold, BUFFER_SIZE);
		//printf("bytes_read: %d\n", bytes_read);
		//printf("hold: %s\n", hold);
		if (bytes_read == -1)
			return (free(hold), NULL);
		hold[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, hold);
		if (len_count(buffer) == 0)
			return (free(buffer), free(hold), NULL);
		if (bytes_read == 0 || ft_strchr(hold, '\n') >= 0)
			break ;
	}
	return (free(hold), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = read_func(fd, buffer);
	//printf("buffer: %s\n",buffer);

	if (!buffer || *buffer == '\0')
		return (free(buffer), NULL);
	size = ft_strchr(buffer, '\n');
	if (size >= 0)
	{
	    // Found newline → extract up to pos + 1
	    line = splitter(buffer, size + 1);
	    buffer = remain(buffer, size + 1);
	}
	else
	{
	    // No newline → return rest of buffer (EOF case)
	    line = splitter(buffer, len_count(buffer));
	    free(buffer);
	    buffer = NULL;
	}
	return (line);
}
	/*if (buffer != NULL)
	{
		size = ft_strchr(buffer, '\n');
		printf("size: %d\n", size);
		if (size == 0)
		{
			printf("here\n");
			if (fd == 0)
			{
				printf("hhhmmmm\n");
				size = len_count(buffer);
			}
			size = ft_strchr(buffer, '\0');
		}
		printf("size: %d\n", size);
		line = splitter(buffer, size + 1);
		buffer = remain(buffer, size + 1);
	}
	else
		free(buffer);*/


#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL) // 0 = stdin
	{
		printf("LINE: %s", line);
		free(line);
	}
	return (0);
}


/*
int	main(void)
{
	int			fd_test;
	char	*str;

	fd_test = 0;//open("test.txt",O_RDONLY);
	while (1)
	{
		str = get_next_line(fd_test);
		printf("lap: >%s<\n",str);
		if (str == NULL)
			break;
		free(str);
	}
	return (0);
}*/
