/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:11:51 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:59:26 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		dest_len;
	char	*dest;

	len = 0;
	dest_len = str_len(src);
	dest = (char *)malloc(dest_len + 1);
	if (!dest)
		return (NULL);
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("%s",ft_strdup("abcdefghijklmnopqrstuvwx
	yzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()\n"));
	return (0);
}*/
