/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:04:16 by username          #+#    #+#             */
/*   Updated: 2026/03/31 13:59:02 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	destory_all(char *str, t_program *program, pthread_mutex_t *dongles,
	t_config *config)
{
	int	i;

	i = 0;
	if (str)
	{
		write(2, str, strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->compile_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&config->scheduler.lock);
	while (i < config->number_of_coders)
	{
		pthread_mutex_destroy(&dongles[i]);
		i++;
	}
	free(program->coders);
	free(dongles);
	free(config->scheduler.queue);
	free(config->scheduler.order);
}

int	check_if_all_ate(t_coders *coders)
{
	int	i;
	int	finished_compiling;

	i = 0;
	finished_compiling = 0;
	if (coders->config->number_of_compiles_required == -1)
		return (0);
	while (i < coders->config->number_of_coders)
	{
		pthread_mutex_lock(coders[i].compile_lock);
		if (coders[i].number_of_compiles
			>= coders->config->number_of_compiles_required)
			finished_compiling++;
		pthread_mutex_unlock(coders[i].compile_lock);
		i++;
	}
	if (finished_compiling == coders->config->number_of_coders)
	{
		pthread_mutex_lock(coders[0].dead_lock);
		*coders->burnt_out = 1;
		pthread_mutex_unlock(coders[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_coders	*coders;

	coders = (t_coders *)pointer;
	while (1)
		if (check_if_dead(coders) == 1 || check_if_all_ate(coders) == 1)
			break ;
	return (pointer);
}

int	thread_create(t_program *program, pthread_mutex_t *dongles
	, t_config *config)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->coders) != 0)
		destory_all("Thread creation error", program, dongles, config);
	i = 0;
	while (i < config->number_of_coders)
	{
		if (pthread_create(&program->coders[i].thread, NULL, &coders_routine,
				&program->coders[i]) != 0)
			destory_all("Thread creation error", program, dongles, config);
		ft_usleep(1);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destory_all("Thread join error", program, dongles, config);
	while (i < config->number_of_coders)
	{
		if (pthread_join(program->coders[i].thread, NULL) != 0)
			destory_all("Thread join error", program, dongles, config);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				n_coders;
	t_program		program;
	t_config		config;
	t_coders		*coders;
	pthread_mutex_t	*dongles;

	n_coders = 0;
	if (argv_check(argc, argv) == 0)
		return (fprintf(stderr, "Incorrect input.\n"
				"Usage:\n./codexion "
				"number_of_coders time_to_burnout time_to_compile "
				"time_to_debug time_to_refactor "
				"number_of_compiles_required dongle_cooldown scheduler\n"), 1);
	coders = malloc((atoi(argv[1]) + 1) * sizeof(t_coders));
	dongles = malloc((atoi(argv[1]) + 1) * sizeof(pthread_mutex_t));
	init_config(&config, argv);
	init_program(&program, coders);
	init_dongles(dongles, atoi(argv[1]));
	init_coders(coders, &program, dongles, argv);
	init_coders_cont(coders, argv, &config);
	init_scheduler(&config, atoi(argv[1]), coders);
	thread_create(&program, dongles, &config);
	destory_all(NULL, &program, dongles, &config);
	return (0);
}
