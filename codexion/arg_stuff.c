/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:44:12 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:58:33 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	is_valid_scheduler(const char *s)
{
	return (strcmp(s, "fifo") == 0 || strcmp(s, "edf") == 0);
}

int	argv_check(int argc, char **argv)
{
	if (argc != 9)
		return (0);
	if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0
		|| atoi(argv[4]) <= 0 || atoi(argv[5]) <= 0 || atoi(argv[7]) < 0)
		return (0);
	if (!is_valid_scheduler(argv[8]))
		return (0);
	return (1);
}
