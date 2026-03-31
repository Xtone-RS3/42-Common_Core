/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:41:28 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:41:45 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_scheduler(t_config *config, int n, t_coders *coders)
{
	int	i;

	config->scheduler.queue = malloc(sizeof(int) * n);
	config->scheduler.order = malloc(sizeof(long) * n);
	config->scheduler.counter = 0;
	config->scheduler.size = 0;
	config->scheduler.capacity = n;
	config->scheduler.coders = coders;
	pthread_mutex_init(&config->scheduler.lock, NULL);
	pthread_cond_init(&config->scheduler.cond, NULL);
	i = 0;
	while (i < n)
	{
		heap_push(&config->scheduler, i + 1);
		i++;
	}
}

void	init_config(t_config *config, char **argv)
{
	config->number_of_coders = atoi(argv[1]);
	config->base_burnout_time = atoi(argv[2]);
	config->base_compile_time = atoi(argv[3]);
	config->base_debug_time = atoi(argv[4]);
	config->base_refactor_time = atoi(argv[5]);
	config->number_of_compiles_required = atoi(argv[6]);
	config->dongle_cooldown = atoi(argv[7]);
	config->scheduler.name = argv[8];
}
