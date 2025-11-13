/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:08:13 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/10 15:08:14 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*result;

	result = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (result[i] == (const char)c)
			return ((void *)&result[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "1234";

	printf("%s\n%s\n",str,ft_memchr(str,'3',4));
	return (0);
}*/
