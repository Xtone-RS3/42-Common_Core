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

	if (size == 0)
		return (NULL);
	i = 0;
	line = ft_calloc(size + 1, 1);
	if (!line)
		return (free(buffer), NULL);
	while (i != size)
	{
		line[i] = buffer [i];
		i++;
	}
	return (line);
}

char	*remain(char *buffer, int size)
{
	int		i;
	int		j;
	char	*result;

	if (size == 0)
		return (NULL);
	i = 0;
	j = 0;
	while ((size + i - 1) < len_count(buffer) && size != 0)
		i++;
	result = ft_calloc(i + 1, 1);
	if (!result)
		return (free(buffer), NULL);
	while (j < i && size < len_count(buffer))
		result[j++] = buffer[size++];
	return (free(buffer), result);
}

char	*read_func(int fd, char *buffer)
{
	char	*hold;
	int		bytes_read;

	hold = ft_calloc(BUFFER_SIZE + 1, 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, hold, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(hold), NULL);
		hold[bytes_read] = 0;
		buffer = ft_strjoin_gnl(buffer, hold);
		if (len_count(buffer) == 0)
			return (free(buffer), free(hold), NULL);
		if (ft_strchr_gnl(hold, '\n'))
			break ;
	}
	return (free(hold), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer[fd] = read_func(fd, buffer[fd]);
	if (buffer[fd] != NULL)
	{
		size = ft_strchr_gnl(buffer[fd], '\n');
		if (size == 0)
			size = ft_strchr_gnl(buffer[fd], '\0');
		line = splitter(buffer[fd], size);
		buffer[fd] = remain(buffer[fd], size);
	}
	else
		free(buffer[fd]);
	return (line);
}

/*int	main(void)
{
	int			fd_test;
	char	*str;

	fd_test = open("test.txt",O_RDONLY);
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
