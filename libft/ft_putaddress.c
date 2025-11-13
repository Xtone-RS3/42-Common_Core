/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:30:11 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:59:48 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	calc_ad(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	printer_ad(char *str)
{
	int	len;

	len = calc_ad(str);
	if (len == 1 && str[0] == '0')
	{
		write(1, "(nil)", 5);
	}
	else
	{
		write(1, "0x", 2);
		while (len != 0)
		{
			write(1, &str[len - 1], 1);
			len--;
		}
	}
}

int	bad_base_ad(char *str)
{
	int	len;
	int	len2;

	len = 0;
	if (*str == '\0')
		return (0);
	else if (str[1] == '\0')
		return (0);
	while (str[len])
	{
		len2 = len + 1;
		while (str[len2])
		{
			if (str[len] == str[len2] || str[len] == '+' || str[len] == '-'
				|| (str[len] >= 9 && str[len] <= 13) || str[len] == ' ')
				return (0);
			len2++;
		}
		len++;
	}
	return (1);
}

int	ft_putaddress(long unsigned int nbr)
{
	long unsigned int	buffer[2];
	char				result[64];
	int					len;
	char				*base;

	base = "0123456789abcdef";
	len = 0;
	buffer[1] = calc_ad(base);
	if (bad_base_ad(base))
	{
		buffer[0] = nbr;
		while (buffer[0] >= buffer[1])
		{
			result[len] = base[buffer[0] % buffer[1]];
			buffer[0] = buffer[0] / buffer[1];
			len++;
		}
		result[len] = base[buffer[0]];
		result[len + 1] = '\0';
		printer_ad(result);
	}
	if (!nbr)
		len = len + 2;
	return (len + 3);
}
