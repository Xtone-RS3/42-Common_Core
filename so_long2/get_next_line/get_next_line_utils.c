/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:25:09 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/20 11:25:10 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	len_count(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin_gnl(char *buffer, char *hold)
{
	int		i;
	int		j;
	char	*result;

	if (buffer == NULL)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (NULL);
	}
	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (len_count(buffer) + len_count(hold) + 1));
	if (!result)
		return (NULL);
	while (buffer[j])
	{
		result[j] = buffer[j];
		j++;
	}
	while (hold[i])
		result[j++] = hold[i++];
	result[j] = '\0';
	free(buffer);
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*result;

	result = (void *)malloc(elsize * nelem);
	if (!result)
		return (NULL);
	ft_bzero(result, elsize * nelem);
	return (result);
}

int	ft_strchr_gnl(char *buffer, char chr)
{
	int	i;

	i = 0;
	while (i <= len_count(buffer))
	{
		if (buffer[i] == chr)
			return (i + 1);
		i++;
	}
	return (0);
}
