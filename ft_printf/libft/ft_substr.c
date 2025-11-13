/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 10:39:57 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/12 10:39:58 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	len_count_sub(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*str;
	size_t	result_len;

	if (!s)
		return (NULL);
	if ((size_t)ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	str = (char *)s + start;
	if (len_count_sub(str) < len)
		result_len = len_count_sub(str) + 1;
	else
		result_len = len + 1;
	result = malloc(result_len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str, result_len);
	return (result);
}

/*
int	main(void)
{
	char	s[] = "hello";

	// Case 1: Normal case
	printf("Result 1: %s\n", ft_substr(s, 1, 3)); // Expect: "ell"

	// Case 2: len larger than remaining string
	printf("Result 2: %s\n", ft_substr(s, 3, 10)); // Expect: "lo"

	// Case 3: start beyond string length
	printf("Result 3: %s\n", ft_substr(s, 10, 2)); // Expect: ""

	// Case 4: Empty string
	printf("Result 4: %s\n", ft_substr("", 0, 2)); // Expect: ""

	// Case 5: NULL string (if allowed)
	printf("Result 5: %s\n", ft_substr(NULL, 0, 2)); // Expect: (null) or crash

}
*/
/*
int	main(void)
{
	char	s[] = "hola";
	char	*str;

	str = ft_substr(s, 4294967295, 0);
	printf("result: %s\n",str);
	free(str);
}*/