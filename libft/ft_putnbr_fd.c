/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:21:51 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:57:23 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb == 0)
		write(fd, "0", 1);
	while (nb > 0)
	{
		str[len++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (len--)
		write(fd, &str[len], 1);
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
