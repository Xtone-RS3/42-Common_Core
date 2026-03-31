/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:34:28 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:58:20 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	refactor(t_coders *coders)
{
	print_message("is refactoring", coders, coders->id);
	ft_usleep(coders->time_to_refactor);
}

void	debug(t_coders *coders)
{
	print_message("is debugging", coders, coders->id);
	ft_usleep(coders->time_to_debug);
}

void	compile(t_coders *coders)
{
	pthread_mutex_lock(coders->r_dongle);
	print_message("has taken a dongle", coders, coders->id);
	if (coders->config->number_of_coders == 1)
	{
		ft_usleep(coders->time_to_burnout);
		pthread_mutex_unlock(coders->r_dongle);
		return ;
	}
	pthread_mutex_lock(coders->l_dongle);
	print_message("has taken a dongle", coders, coders->id);
	coders->compiling = 1;
	print_message("is compiling", coders, coders->id);
	pthread_mutex_lock(coders->compile_lock);
	coders->last_compile_time = get_current_time();
	coders->number_of_compiles++;
	pthread_mutex_unlock(coders->compile_lock);
	ft_usleep(coders->time_to_compile);
	coders->compiling = 0;
}

// Thread routine

		// pthread_mutex_lock(&coders->config->scheduler.lock);

		// while (!dead_loop(coders))
		// {
		// 	if (heap_peek(&coders->config->scheduler) == coders->id)
		// 	{
		// 		heap_pop(&coders->config->scheduler);
		// 		break;
		// 	}
		// 	pthread_cond_wait(&coders->config->scheduler.cond,
		// 		&coders->config->scheduler.lock);
		// }

		// pthread_mutex_unlock(&coders->config->scheduler.lock);

void	*coders_routine(void *pointer)
{
	t_coders	*coders;

	coders = (t_coders *)pointer;
	while (!dead_loop(coders))
	{
		compile(coders);
		pthread_mutex_lock(&coders->config->scheduler.lock);
		heap_push(&coders->config->scheduler, coders->id);
		pthread_cond_broadcast(&coders->config->scheduler.cond);
		pthread_mutex_unlock(&coders->config->scheduler.lock);
		start_dongle_cooldown(coders->l_dongle,
			coders->config->dongle_cooldown);
		start_dongle_cooldown(coders->r_dongle,
			coders->config->dongle_cooldown);
		debug(coders);
		refactor(coders);
	}
	return (pointer);
}
