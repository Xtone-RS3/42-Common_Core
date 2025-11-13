/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:08:45 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/09 17:08:49 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	int		result;

	if (n == 0)
		return (0);
	len = 0;
	result = 0;
	while ((s1[len] && (s1[len] == s2[len])) && len < n)
		len = len + 1;
	if (len < n)
		result = (unsigned char)s1[len] - (unsigned char)s2[len];
	return (result);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char *s1;
	char *s2;
	int x;
	int y;

	s1 = "abcdef";
	s2 = "abc\375xx";
	x = ft_strncmp(s1,s2,5);
	y = strncmp(s1,s2,5);
	printf("mine: %d\nnot: %d\n",x,y);
	return (0);
}*/
