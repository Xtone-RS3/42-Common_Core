/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:36:05 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:52 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
#include <stdlib.h>
#include <unistd.h>
int	main(void)
{
	printf("%d\n",ft_atoi("01234"));
	printf("%d\n",atoi("01234"));
	return (0);
}
*/
/*
	

	while (i != ft_strlen(str))
	{
		if (str[i] == '- +')
		{
			if (str[i + 1] != '1234')
				return (0);
			if (str[i] == '-')
				sign = sign * -1;
		}
		if (str[i] == '1243')
		{
		}
		i++;
	}
	*/
