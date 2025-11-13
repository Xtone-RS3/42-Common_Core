/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:41:23 by gasoares          #+#    #+#             */
/*   Updated: 2025/10/31 11:57:31 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_count_fd(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putchar_fd_2(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i != len_count_fd(s))
	{
		ft_putchar_fd_2(s[i], fd);
		i++;
	}
	ft_putchar_fd_2('\n', fd);
}

/*
#include <fcntl.h>   // open
#include <unistd.h>  // write, close
#include <stdio.h>   // perror
#include <stdlib.h>  // exit

// Include your previously written functions here

int main(void)
{
	// Test 1: Normal use - print to stdout
	ft_putendl_fd("Test 1: Hello, stdout!\n", 1);

	// Test 2: Print to stderr
	ft_putendl_fd("Test 2: Error message to stderr.\n", 2);

	// Test 3: Print to a file
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd("Test 3: This goes into output.txt\n", fd);
	close(fd);

	// Test 4: NULL string (should ideally not crash)
	ft_putendl_fd(NULL, 1); // Your current code will segfault here

	// Test 5: Invalid file descriptor
	ft_putendl_fd("Test 5: Should not be printed (bad fd).\n", -1); //no print

	// Test 6: Single character write
	ft_putendl_fd("X", 1);
	//ft_putchar_fd('\n', 1);

	return 0;
}*/