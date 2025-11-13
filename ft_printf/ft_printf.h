/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:05:28 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/18 14:05:30 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>

int			ft_printf(const char *format, ...);
int			ft_putchar_print(char c);
int			ft_putnbr_print(long n);
int			ft_putstr_print(char *s);
int			ft_putnbr_un(unsigned int n);
int			ft_putnbr_base(unsigned int nbr, char *base);
int			ft_putaddress(long unsigned int nbr);

#endif