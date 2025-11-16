/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 12:10:03 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:56:46 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_count_j(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (len_count_j(s1) + len_count_j(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[j])
	{
		result[j] = s1[j];
		j++;
	}
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

/*
int	main(void)
{
	char	s1[] = "tripouille";
	char	s2[] = "42";

	char *joined = ft_strjoin(s1, s2);
	if (joined)
	{
		printf("Joined string: %s\n", joined);
		free(joined);
	}
	else
	{
		printf("Allocation failed\n");
	}
	return (0);
}*/
