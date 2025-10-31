/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:10:30 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:59:14 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len = len + 1;
	return (len);
}

//int	main(void)
//{
//	int	x;
//
//	x = ft_strlen("hello wolr");
//	printf("result = %d\n", x);
//	return (0);
//}
