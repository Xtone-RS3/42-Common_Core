/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:09:07 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:56:27 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//TODO
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
/*{
	size_t	len;

	len = 0;
	while (src[len] != '\0' && len < size)
	{
		dest[len] = src[len];
		len++;
	}
	while (len < size)
	{
		dest[len] = '\0';
		len++;
	}
	return (len);
}*/

/*
int main(void)
{
	//unsigned int omega;
	int omegaiguess;
	char dest[4];
	char *src = "omegalul";

	//omega = strlcpy("lol","lul",3);
	//printf("%d",omega);
	omegaiguess = ft_strlcpy(dest,src,4);
	printf("%d",omegaiguess);
	printf("%s",dest);
	return (0);
}
*/
