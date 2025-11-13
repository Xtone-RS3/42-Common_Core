/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 16:23:41 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/12 16:23:42 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	len_count_putnbr(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_putnbr(int nb)
{
	char	*result;
	int		len;
	long	n;

	result = ft_calloc(12, sizeof(char));
	if (!result)
		return (NULL);
	n = nb;
	len = 0;
	if (n < 0)
	{
		result[len++] = '-';
		n = -n;
	}
	if (n == 0)
		result[len++] = '0';
	while (n > 0)
	{
		result[len++] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

void	str_invert(char *result, int i, char *hold, int size)
{
	while (i < len_count_putnbr(hold))
	{
		result[i] = hold[size - i - 1];
		i++;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*hold;
	char	*result;
	int		i;

	i = 0;
	hold = ft_putnbr(n);
	if (!hold)
		return (NULL);
	size = len_count_putnbr(hold);
	result = (char *)ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (hold[i] == '-')
	{
		result[i++] = '-';
		size = size + 1;
	}
	str_invert(result, i, hold, size);
	free(hold);
	return (result);
}

/* int	main(void)
{
	int		n;
	char	*str;

	n = 12;
	str = ft_itoa(n);
	printf("result: %s\n",str);
	free(str);
	//printf("result: %s\n",ft_itoa(-2147483647));
	return (0);
} */
