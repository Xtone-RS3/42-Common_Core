/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:21:51 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/13 11:21:52 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

int	ft_putchar_print(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_print(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_print('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_print(n / 10);
	count += ft_putchar_print(n % 10 + '0');
	return (count);
}

int	ft_putnbr_un(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_un(n / 10);
	count += ft_putchar_print(n % 10 + '0');
	return (count);
}

/*
int	main(void)
{
	ft_putnbr_fd(-512345, 1);     // Should print 12345
	write(1, "\n", 1);          // Newline for readability

	ft_putnbr_fd(0, 1);         // Should print 0
	write(1, "\n", 1);

	ft_putnbr_fd(987654321, 1); // Should print 987654321
	write(1, "\n", 1);

	return (0);
}*/
