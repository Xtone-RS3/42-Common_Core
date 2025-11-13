/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:26:08 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:58:35 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (c);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (c);
	else
		return (0);
}

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	else
		return (0);
}

int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (c);
	else
		return (0);
}
