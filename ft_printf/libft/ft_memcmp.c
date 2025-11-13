/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:13:07 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/10 16:13:08 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char s[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};

	printf("ft:  %d\n",ft_memcmp(s, s2, 1));
	printf("def: %d\n",memcmp(s, s2, 1));
	printf("ft:  %d\n",ft_memcmp(s2, s, 1));
	printf("def: %d\n",memcmp(s2, s, 1));
	return (0);
}*/
