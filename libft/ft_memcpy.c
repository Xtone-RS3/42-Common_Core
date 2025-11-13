/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:36:40 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:00 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	if (!dest && !src)
		return (NULL);
	ptr_d = (unsigned char *)dest;
	ptr_s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char str_a[10] = "12345";
	char buffer1[10] = "12345";

	printf("Before memcpy (overlap test): %s\n", str_a);
	memcpy(str_a + 2, str_a, 4);
	printf("After memcpy  (overlap test): %s\n", str_a);
	memmove(buffer1 + 2, buffer1, 4);
	printf("After memmove (overlap test): %s\n", buffer1);

	return 0;
}*/
