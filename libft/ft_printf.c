/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:45:56 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 12:07:21 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_func(char format, va_list args)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_putchar_print(va_arg(args, int));
	else if (format == 's')
		i += ft_putstr_print(va_arg(args, char *));
	else if (format == 'p')
		i += ft_putaddress(va_arg(args, long unsigned));
	else if (format == 'd' || format == 'i')
		i += ft_putnbr_print(va_arg(args, int));
	else if (format == 'u')
		i += ft_putnbr_un(va_arg(args, unsigned int));
	else if (format == 'x')
		i += ft_putnbr_base(va_arg(args, unsigned), "0123456789abcdef");
	else if (format == 'X')
		i += ft_putnbr_base(va_arg(args, unsigned), "0123456789ABCDEF");
	else if (format)
		i += ft_putchar_print(format);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format != 0)
	{
		if (*format == '%')
			i += format_func(*(++format), args);
		else
			i += ft_putchar_print(*format);
		++format;
	}
	va_end(args);
	return (i);
}

/*
int	main(void)
{
	char			c_test;
	char			*s_test;
	int				p_test;
	int				d_test;
	int				i_test;
	unsigned int	u_test;
	int				xx_test;
	int				XX_test;

	c_test = 's';
	s_test = "string23453452345";
	p_test = '3';
	d_test = 44;
	i_test = 11;
	u_test = 88;
	xx_test = 1234;
	XX_test = 4321;

	//printf("%%c n: %d\n", printf("%%c: %c\n",c_test));
	//printf("%%c n: %d\n", ft_printf("%%c: %c\n",c_test));

	printf("%%s n: %d\n", printf("%%s: %s\n",s_test));
	printf("%%s n: %d\n", ft_printf("%%s: %s\n",s_test));
	//printf(" NULL %s NULL \n", NULL);
	//ft_printf(" NULL %s NULL \n", NULL);

	printf("%%p n: %d\n", printf("%%p: %p\n",&p_test));
	printf("%%p n: %d\n", ft_printf("%%p: %p\n",&p_test));

	printf("%%d n: %d\n", printf("%%d: %d\n",d_test));
	printf("%%d n: %d\n", ft_printf("%%d: %d\n",d_test));

	printf("%%i n: %d\n", printf("%%i: %i\n",i_test));
	printf("%%i n: %d\n", ft_printf("%%i: %i\n",i_test));

	printf("%%u n: %d\n", printf("%%u: %u\n",u_test));
	printf("%%u n: %d\n", ft_printf("%%u: %u\n",u_test));

	printf("%%x n: %d\n", printf("%%x: %x\n",xx_test));
	printf("%%x n: %d\n", ft_printf("%%x: %x\n",xx_test));

	printf("%%X n: %d\n", printf("%%X: %X\n",XX_test));
	printf("%%X n: %d\n", ft_printf("%%X: %X\n",XX_test));
	
	printf("%% n: %d\n", printf("%%: %%%%%%\n"));
	printf("%% n: %d\n", ft_printf("%%: %%%%%%\n"));
	return (0);
}*/

/*
#include <stdio.h> 
#include <stdlib.h>
int	main(void)
{
		int len = ft_printf("%s6789", "012345");
		printf(" %d", len);
		printf("\n%d\n", 23232);
		ft_printf(" \n>>>>>>>>>>>>>>>>>> %X\n", 42);
		ft_printf(" \n>>>>>>>>>>>>>>>>>> %u\n", 42);

		char	*t = malloc (12);
		printf("\naaaaaaaaaaa : %p\n", t);
		ft_printf("\nbbbbbbbbbbb: %p", t);

		printf("\n%%\n");
		ft_printf("\n%%\n");

	printf("---------------------------------------------------");
	    int a1 = ft_printf("Char: %c\n", 'A');
	    int z1 = printf("Char: %c\n", 'A');
	    printf("lenght is : %d\n", a1);
	    printf("cmp: %d\n\n", (a1 == z1));

	    int a2 = ft_printf("String: %s\n", "Hello");
	    int z2 = printf("String: %s\n", "Hello");
	    printf("lenght is : %d\n", a2);
	    printf("cmp: %d\n\n", (a2 == z2));

	    int a3 = ft_printf("Pointer: %p\n", (void *)0x1234);
	    int z3 = printf("Pointer: %p\n", (void *)0x1234);
	    printf("lenght is : %d\n", a3);
	    printf("cmp: %d\n\n", (a3 == z3));

	    int a4 = ft_printf(">>>>>Decimal: %d\n", -42);//todo
	    int z4 = printf(">>>>>Decimal: %d\n", -42);
	    printf("lenght is : %d\n", a4);
	    printf("cmp: %d\n\n", (a4 == z4));

	    int a5 = ft_printf("Integer: %i\n", 42);
	    int z5 = printf("Integer: %i\n", 42);
	    printf("lenght is : %d\n", a5);
	    printf("cmp: %d\n\n", (a5 == z5));

	    int a6 = ft_printf("Unsigned: %u\n", 3000000000u);
	    int z6 = printf("Unsigned: %u\n", 3000000000u);
	    printf("lenght is : %d\n", a6);
	    printf("cmp: %d\n\n", (a6 == z6));

	    int a7 = ft_printf("Hex lower: %x\n", 255);
	    int z7 = printf("Hex lower: %x\n", 255);
	    printf("lenght is : %d\n", a7);
	    printf("cmp: %d\n\n", (a7 == z7));

	    int a8 = ft_printf("Hex upper: %X\n", 255);
	    int z8 = printf("Hex upper: %X\n", 255);
	    printf("lenght is : %d\n", a8);
	    printf("cmp: %d\n\n", (a8 == z8));

	    int a9 = ft_printf("Percent: %%\n");
	    int z9 = printf("Percent: %%\n");
	    printf("lenght is : %d\n", a9);
	    printf("cmp: %d\n\n", (a9 == z9));

	    int b1 = ft_printf("%s", NULL);
	    //int y1 = printf("%s",(void *) 0);
	    printf("lenght is : %d\n", b1);
	   //printf("cmp: %d\n\n", (b1 == y1));

	    int b2 = ft_printf("%p\n", NULL);
	    int y2 = printf("%p\n", NULL);
	    printf("lenght is : %d\n", b2);
	    printf("cmp: %d\n\n", (b2 == y2));

	    int b3 = ft_printf("Test NULL string: %s\n", NULL);
	    //int y3 = printf("Test NULL string: %s\n", NULL);
	    printf("lenght is : %d\n", b3);
	    //printf("cmp: %d\n\n", (b3 == y3));

	    int b4 = ft_printf("Test NULL pointer: %p\n", NULL);
	    int y4 = printf("Test NULL pointer: %p\n", NULL);
	    printf("lenght is : %d\n", b4);
	    printf("cmp: %d\n\n", (b4 == y4));

	    int b5 = ft_printf("Test percent: %%\n");
	    int y5 = printf("Test percent: %%\n");
	    printf("lenght is : %d\n", b5);
	    printf("cmp: %d\n\n", (b5 == y5));

	    int b6 = ft_printf("Test int: %d %i\n", -123, 456);
	    int y6 = printf("Test int: %d %i\n", -123, 456);//todo
	    printf("lenght is : %d\n", b6);
	    printf("cmp: %d\n\n", (b6 == y6));

	    int b7 = ft_printf("Test unsigned: %u\n", 4294967295u);
	    int y7 = printf("Test unsigned: %u\n", 4294967295u);
	    printf("lenght is : %d\n", b7);
	    printf("cmp: %d\n\n", (b7 == y7));

	    int b8 = ft_printf("Test hex lower: %x\n", 3735928559u);
	    int y8 = printf("Test hex lower: %x\n", 3735928559u);
	    printf("lenght is : %d\n", b8);
	    printf("cmp: %d\n\n", (b8 == y8));

	    int b9 = ft_printf("Test hex upper: %X\n", 3735928559u);
	    int y9 = printf("Test hex upper: %X\n", 3735928559u);
	    printf("lenght is : %d\n", b9);
	    printf("cmp: %d\n\n", (b9 == y9));

	    int c1 = ft_printf("Test char: %c\n", 'Z');
	    int x1 = printf("Test char: %c\n", 'Z');
	    printf("lenght is : %d\n", c1);
	    printf("cmp: %d\n\n", (c1 == x1));

	    int c2 = ft_printf("abc%\n");
	    //int x2 = printf("abc%\n");
	    printf("lenght is : %d\n", c2);
	   // printf("cmp: %d\n\n", (c2 == x2));

	    int c3 = ft_printf("abc %s\n", "Hello");
	    int x3 = printf("abc %s\n", "Hello");
	    printf("lenght is : %d\n", c3);
	    printf("cmp: %d\n\n", (c3 == x3));
	int c4 = printf("%d\n", 10);
	int x4 = ft_printf("%d\n", 10);
	ft_printf("lenght is : %d\n", x4);
	printf("cmp : %d\n", (c4 == x4));
    return 0;
}
*/
