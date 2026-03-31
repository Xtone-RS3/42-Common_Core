/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_n_dongles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:48:50 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:58:41 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	dead_loop(t_coders *coders)
{
	pthread_mutex_lock(coders->dead_lock);
	if (*coders->burnt_out == 1)
		return (pthread_mutex_unlock(coders->dead_lock), 1);
	pthread_mutex_unlock(coders->dead_lock);
	return (0);
}

void	*cooldown_thread(void *ptr)
{
	t_cooldown_args	*a;

	a = ptr;
	ft_usleep(a->cooldown_ms);
	pthread_mutex_unlock(a->dongle);
	free(a);
	return (NULL);
}

void	start_dongle_cooldown(pthread_mutex_t *dongle, size_t cooldown_ms)
{
	pthread_t		t;
	t_cooldown_args	*args;

	args = malloc(sizeof(t_cooldown_args));
	args->dongle = dongle;
	args->cooldown_ms = cooldown_ms;
	pthread_create(&t, NULL, cooldown_thread, args);
	pthread_detach(t);
}

int	coder_dead(t_coders *coders, size_t time_to_burnout)
{
	pthread_mutex_lock(coders->compile_lock);
	if (get_current_time() - coders->last_compile_time >= time_to_burnout
		&& coders->compiling == 0)
		return (pthread_mutex_unlock(coders->compile_lock), 1);
	pthread_mutex_unlock(coders->compile_lock);
	return (0);
}

int	check_if_dead(t_coders *coders)
{
	int	i;

	i = 0;
	while (i < coders->config->number_of_coders)
	{
		if (coder_dead(&coders[i], coders[i].time_to_burnout))
		{
			print_message("burned out", &coders[i], coders[i].id);
			pthread_mutex_lock(coders[0].dead_lock);
			*coders->burnt_out = 1;
			pthread_mutex_unlock(coders[0].dead_lock);
			pthread_mutex_lock(&coders[0].config->scheduler.lock);
			pthread_cond_broadcast(&coders[0].config->scheduler.cond);
			pthread_mutex_unlock(&coders[0].config->scheduler.lock);
			return (1);
		}
		i++;
	}
	return (0);
}
