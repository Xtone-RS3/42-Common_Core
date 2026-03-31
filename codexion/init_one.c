/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:39:52 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:58:56 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	init_program(t_program *program, t_coders *coders)
{
	program->dead_flag = 0;
	program->coders = coders;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->compile_lock, NULL);
}

void	init_input(t_coders *coders, char **argv)
{
	coders->time_to_burnout = atoi(argv[2]);
	coders->time_to_compile = atoi(argv[3]);
	coders->time_to_debug = atoi(argv[4]);
	coders->time_to_refactor = atoi(argv[5]);
}

void	init_dongles(pthread_mutex_t *dongles, int coders_num)
{
	int	i;

	i = 0;
	while (i < coders_num)
	{
		pthread_mutex_init(&dongles[i], NULL);
		i++;
	}
}

void	init_coders(t_coders *coders, t_program *program,
		pthread_mutex_t *dongles, char **argv)
{
	int	n_coders;

	n_coders = 0;
	while (n_coders != atoi(argv[1]))
	{
		coders[n_coders].id = n_coders + 1;
		coders[n_coders].compiling = 0;
		coders[n_coders].number_of_compiles = 0;
		init_input(&coders[n_coders], argv);
		coders[n_coders].write_lock = &program->write_lock;
		coders[n_coders].dead_lock = &program->dead_lock;
		coders[n_coders].compile_lock = &program->compile_lock;
		coders[n_coders].burnt_out = &program->dead_flag;
		coders[n_coders].l_dongle = &dongles[n_coders];
		coders[n_coders].start_time = get_current_time();
		coders[n_coders].last_compile_time = get_current_time();
		if (n_coders == 0)
			coders[n_coders].r_dongle = &dongles[atoi(argv[1]) - 1];
		else
			coders[n_coders].r_dongle = &dongles[n_coders - 1];
		n_coders += 1;
	}
}

void	init_coders_cont(t_coders *coders, char **argv, t_config *config)
{
	int	n_coders;

	n_coders = 0;
	while (n_coders != atoi(argv[1]))
	{
		coders[n_coders].config = config;
		n_coders += 1;
	}
}
