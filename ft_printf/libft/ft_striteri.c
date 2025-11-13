/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:50:57 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/12 17:50:58 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	len_count_iteri(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (i != len_count_iteri(s))
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Capitalize letters at even indices
void capitalize_even(unsigned int i, char *c) 
{
    if (i % 2 == 0 && c[i] >= 'a' && c[i] <= 'z')
        c[i] = c[i] - 32;
}

// 2. Shift all letters by +1 (simple Caesar cipher)
void shift_by_one(unsigned int i, char *c) {
    (void)i;
    if ((c[i] >= 'a' && c[i] < 'z') || (c[i] >= 'A' && c[i] < 'Z'))
        c[i] = c[i] + 1;
    else if (c[i] == 'z')
        c[i] = 'a';
    else if (c[i] == 'Z')
        c[i] = 'A';
}

// Helper to safely test ft_striteri without modifying string literals
void test_and_print(const char *label, 
const char *input, void (*func)(unsigned int, char *)) {
    if (!input) {
        printf("%s: Input is NULL\n", label);
        ft_striteri(NULL, func);
        return;
    }

    if (!func) {
        printf("%s: Function pointer is NULL\n", label);
        char *temp = strdup(input);
        ft_striteri(temp, NULL);
        free(temp);
        return;
    }

    char *temp = strdup(input);
    if (!temp) {
        printf("%s: Memory allocation failed\n", label);
        return;
    }

    ft_striteri(temp, func);
    printf("%s: %s\n", label, temp);
    free(temp);
}

int main(void) {
    printf("---- Testing ft_striteri ----\n");

    test_and_print("Test 1 - Capitalize even indices", "hello, world!", 
    capitalize_even);
    test_and_print("Test 2 - Caesar shift", "abcdefZz", shift_by_one);
    test_and_print("Test 3 - Empty string", "", capitalize_even);
    test_and_print("Test 4 - NULL string", NULL, capitalize_even);
    test_and_print("Test 5 - NULL function", "hello", NULL);

    return 0;
}*/
