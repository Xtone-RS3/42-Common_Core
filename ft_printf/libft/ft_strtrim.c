/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:24:20 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/12 13:24:21 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	len_count_trim(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	char_in_set_2(char c, char const *set)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	while (s1[start] && char_in_set_2(s1[start], set))
		start++;
	end = len_count_trim(s1);
	while (end > start && char_in_set_2(s1[end - 1], set))
		end--;
	result = malloc(sizeof(*s1) * (end - start + 1));
	if (!result)
		return (NULL);
	while (start < end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}

/*
int main(void)
{
    char *result;

    // Test 1
    // Input: "1234", Set: "23"
    // Expected output: "1234"
    // Explanation: No trimming at start/end because '1' and '4' are not in set
    result = ft_strtrim("------", "-");
    printf("Input: \"------\", Set: \"-\" -> Result: \"%s\"\n", result);
    free(result);

    // Test 2
    // Input: "23123423", Set: "25"
    // Expected output: "3123423"
    // Explanation: '2' at start removed; '3' is not in set, 
    // No trimming at end since '3' is not in set.
    result = ft_strtrim("23123423", "25");
    printf("Input: \"23123423\", Set: \"25\" -> Result: \"%s\"\n", result);
    free(result);

    // Test 3
    // Input: "32123423", Set: "25"
    // Expected output: "32123423"
    // Explanation: Start and end characters ('3' and '3') not in 
    result = ft_strtrim("32123423", "25");
    printf("Input: \"32123423\", Set: \"25\" -> Result: \"%s\"\n", result);
    free(result);

    // Test 4
    // Input: "52123425", Set: "25"
    // Expected output: "1234"
    // Explanation: '5' and '2' removed from both start and end
    result = ft_strtrim("52123425", "25");
    printf("Input: \"52123425\", Set: \"25\" -> Result: \"%s\"\n", result);
    free(result);

    return 0;
}*/
