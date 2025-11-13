/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:32:45 by gasoares          #+#    #+#             */
/*   Updated: 2025/07/24 11:32:48 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		result;

	result = 0;
	if (nbr >= 16)
		result += ft_putnbr_base(nbr / 16, base);
	result += ft_putchar_print(base[nbr % 16]);
	return (result);
}

/*
#include <stdio.h>
int main(void)
{
	int n;

	n = 894867;
	//printf("%d",bad_base("abcc"));
	ft_putnbr_base(n,"0123456789abcdef");
	return (0);
}*/
/*

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;//[0] = n
	unsigned int	base_len;// [1] = base_len
	char			result[33];
	int				len;

	len = 0;
	base_len = calc(base);
	if (bad_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = nbr * -1;
		}
		else
			n = nbr;
		while (n >= base_len)
		{
			result[len] = base[n % base_len];
			n = n / base_len;
			len++;
		}
		result[len] = base[n];
		result[len + 1] = '\0';
		printer(result);
	}
}*/