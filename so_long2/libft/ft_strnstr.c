/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:47:06 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:56:15 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_counter_2(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	finder(const char *str, const char *to_find, size_t start)
{
	size_t	len;
	size_t	held;
	size_t	h_len;
	size_t	n_len;

	held = start;
	len = 0;
	h_len = len_counter_2(str);
	n_len = len_counter_2(to_find);
	while ((start != h_len) && (str[start] == to_find[len]))
	{
		n_len--;
		if (n_len == 0)
			return (held);
		len++;
		start++;
	}
	held = held + 1;
	return (held);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	len;
	size_t	hold;
	char	*ptr;

	len = 0;
	while ((len != len_counter_2(str)) && (len <= size))
	{
		hold = len;
		len = finder(str, to_find, hold);
		if (len == hold && ((len + len_counter_2(to_find)) <= size))
		{
			ptr = (char *)(&str[len]);
			return (ptr);
		}
		else if ((len + len_counter_2(to_find)) > size)
			break ;
	}
	ptr = ((void *) 0);
	if (len_counter_2(to_find) == 0)
		ptr = (char *)(&str[0]);
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>
//#include <bsd/string.h>

int main(void)
{
	char haystack[30] = "aaabcabcd";
	//char *str;

	//str = ft_strnstr(haystack, "cd", 9);
	printf("6: %s\n",ft_strnstr(haystack, "cd", 6));
	printf("7: %s\n",ft_strnstr(haystack, "cd", 7));
	printf("8: %s\n",ft_strnstr(haystack, "cd", 8));
	printf("9: %s\n",ft_strnstr(haystack, "cd", 9));
	return(0);
}*/
