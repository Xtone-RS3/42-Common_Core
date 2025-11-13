/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:09:49 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:56:58 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = c;
	if (ch == '\0')
	{
		i = ft_strlen(s);
		return ((char *)s + i++);
	}
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main() {
	char s[] = "tripouille";
	//char ch = 'o';

	char *result = ft_strchr(s, 't' + 256);

	if (result != NULL) {
		printf("Character '%c' found at position: %ld\n", 't' + 256, result - s);
		printf("Remaining string from character: \"%s\"\n", result);
	} else {
		printf("Character '%c' not found in the string.\n", 't' + 256);
	}

	return 0;
}*/