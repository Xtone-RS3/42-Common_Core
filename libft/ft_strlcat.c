/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:09:28 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:56:34 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_counter(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	src_len;

	len = 0;
	i = 0;
	src_len = len_counter(src);
	while (dest[len] != '\0' && len < size)
		len = len + 1;
	if (len == size)
	{
		size = size + src_len;
		return (size);
	}
	while (src[i] != '\0' && (len + i + 1) < size)
	{
		dest[len + i] = src[i];
		i++;
	}
	if (len + i < size)
		dest[len + i] = '\0';
	len = len + src_len;
	return (len);
}

/*
#include <string.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
	char dest[5] = "Hell";
	char *src = "oWorld";
	unsigned int size;
	int x;
	//int y;

	size = 3;
	x = ft_strlcat(dest,src,size);
	//y = strlcat(dest,src,size);
	printf("%d\n",x);
	return (0);
}
*/
