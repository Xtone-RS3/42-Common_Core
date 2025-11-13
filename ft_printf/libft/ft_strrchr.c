/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:40:59 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/10 11:41:00 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)(&s[len]));
		len--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main() {
	char *text = "Hello, world!";
	char ch = 'Y';

	char *result = ft_strrchr(text, ch);

	if (result != NULL) {
		printf("Character '%c' found at position: %ld\n", ch, result - text);
		printf("Remaining string from character: \"%p\"\n", result);
	} else {
		printf("Character '%c' not found in the string.\n", ch);
		printf("Remaining string from character: \"%p\"\n", result);
	}

	return 0;
}
*/