/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 14:51:52 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/12 14:51:53 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	set_counter(char const *s, char c)
{
	int	i;
	int	result;

	result = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			result++;
		if (i > 0 && s[i - 1] == c && s[i] != c)
			result++;
		i++;
	}
	return (result);
}

int	len_count_split(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*splitter(char const *s, int size)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while (i != size)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		index;
	int		start;

	index = 0;
	i = 0;
	start = 0;
	result = malloc(sizeof(char *) * (set_counter(s, c) + 1));
	if (!result)
		return (NULL);
	while (start != (len_count_split(s) + 1))
	{
		if (s[start] != c && s[start] != '\0')
			i++;
		if ((s[start] == c || s[start] == '\0') && i != 0)
		{
			result[index] = splitter(&s[start - i], i);
			index++;
			i = 0;
		}
		start++;
	}
	result[index] = NULL;
	return (result);
}

/*
void print_split_result(char **result) {
    int i = 0;
    while (result && result[i]) {
        printf("  result[%d] = \"%s\"\n", i, result[i]);
        i++;
    }
    printf("  result[%d] = NULL\n", i);
}

void free_split_result(char **result) {
    int i = 0;
    while (result && result[i]) {
        //free(result[i]);
        i++;
    }
    //free(result);
}

void test_case(const char *s, char c) {
    printf("Test: s = \"%s\", delimiter = '%c'\n", s, c);
    char **res = ft_split(s, c);
    if (!res) {
        printf("  ft_split returned NULL (possibly malloc failure)\n\n");
        return;
    }
    print_split_result(res);
    free_split_result(res);
    printf("\n");
}

int main(void) {
	test_case("   lorem   ipsum dolor     sit amet, consectetu", ' ');
    test_case("hello", 'l');             // Repeated delimiter
    test_case("omega", 'm');             // Single delimiter
    test_case("omomomomo", 'm');         // Alternating
    test_case("omomomomo", 'o');         // Delimiter at start and end
    test_case("aaaaa", 'a');             // Only delimiters
    test_case("", 'x');                  // Empty string
    test_case("abc", 'x');               // No delimiter
    test_case("xabcxdefx", 'x');         // Delimiter at start, middle, end
    test_case("  hello world  ", ' ');   // Space as delimiter
    test_case("one,,two,,three", ',');   // Multiple consecutive delimiters

    return 0;
}*/
