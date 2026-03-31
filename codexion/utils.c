/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:36:43 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:58:34 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_message(char *str, t_coders *coders, int id)
{
	size_t	time;

	pthread_mutex_lock(coders->write_lock);
	time = get_current_time() - coders->start_time;
	if (!dead_loop(coders))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(coders->write_lock);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	swap_nodes(t_scheduler *s, int a, int b)
{
	int		tmp_id;
	long	tmp_order;

	tmp_id = s->queue[a];
	tmp_order = s->order[a];
	s->queue[a] = s->queue[b];
	s->order[a] = s->order[b];
	s->queue[b] = tmp_id;
	s->order[b] = tmp_order;
}
