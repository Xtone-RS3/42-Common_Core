/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:00:07 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/10 13:00:08 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		n--;
		while (n >= 0)
		{
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char str_a[10] = "12345678";
	char buffer1[10] = "12345678";

	printf("Before memcpy (overlap test): %s\n", str_a);
	memmove(str_a + 2, str_a, 4);
	printf("After memcpy  (overlap test): %s\n", str_a);
	ft_memmove(buffer1 + 2, buffer1, 4);
	printf("After memmove (overlap test): %s\n", buffer1);

	return 0;
}*/