/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:59:09 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:56:22 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_count_mapi(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	result = malloc(sizeof(char) * (len_count_mapi(s) + 1));
	if (!result)
		return (NULL);
	while (i != len_count_mapi(s))
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
// 1. Capitalize characters at even index
char capitalize_even(unsigned int i, char c) {
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

// 2. Replace vowels with '*'
char replace_vowels(unsigned int i, char c) {
    (void)i; // unused
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return '*';
    return c;
}

// 3. Return index as char (for fun/testing purposes)
char index_as_char(unsigned int i, char c) {
    (void)c;
    return (i % 10) + '0'; // returns '0'..'9'
}

int main(void) {
    const char *test1 = "hello, world!";
    const char *test2 = "";
    const char *test3 = NULL;

    char *result;

    printf("---- Test 1: Normal Input ----\n");
    result = ft_strmapi(test1, capitalize_even);
    if (result)
        printf("capitalize_even: %s\n", result);
    else
        printf("Returned NULL\n");
    free(result);

    printf("---- Test 2: Empty String ----\n");
    result = ft_strmapi(test2, replace_vowels);
    if (result)
        printf("replace_vowels: \"%s\"\n", result);
    else
        printf("Returned NULL\n");
    free(result);

    printf("---- Test 3: NULL String ----\n");
    result = ft_strmapi(test3, capitalize_even);
    if (result)
        printf("Unexpected result: %s\n", result);
    else
        printf("Correctly returned NULL for NULL string\n");

    printf("---- Test 4: NULL Function Pointer ----\n");
    result = ft_strmapi(test1, NULL);
    if (result)
        printf("Unexpected result: %s\n", result);
    else
        printf("Correctly returned NULL for NULL function\n");

    printf("---- Test 5: Replace vowels with '*' ----\n");
    result = ft_strmapi("Education is powerful!", replace_vowels);
    if (result)
        printf("replace_vowels: %s\n", result);
    else
        printf("Returned NULL\n");
    free(result);

    printf("---- Test 6: Index as character ----\n");
    result = ft_strmapi("abcdef", index_as_char);
    if (result)
        printf("index_as_char: %s\n", result); // Expected: "012345"
    else
        printf("Returned NULL\n");
    free(result);

    return 0;
}*/
