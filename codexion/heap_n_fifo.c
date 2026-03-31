/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_n_fifo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:45:35 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:59:08 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	heapify_up_fifo(t_scheduler *scheduler, int i)
{
	int	parent;

	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (scheduler->order[i] >= scheduler->order[parent])
			break ;
		swap_nodes(scheduler, i, parent);
		i = parent;
	}
}

void	heapify_down_fifo(t_scheduler *scheduler, int i)
{
	int	left;
	int	right;
	int	smallest;

	while (1)
	{
		left = 2 * i + 1;
		right = 2 * i + 2;
		smallest = i;
		if (left < scheduler->size
			&& scheduler->order[left]
			< scheduler->order[smallest])
			smallest = left;
		if (right < scheduler->size
			&& scheduler->order[right]
			< scheduler->order[smallest])
			smallest = right;
		if (smallest == i)
			break ;
		swap_nodes(scheduler, i, smallest);
		i = smallest;
	}
}

int	heap_push(t_scheduler *scheduler, int coder_id)
{
	t_coders	*c;

	if (scheduler->size >= scheduler->capacity)
		return (-1);
	scheduler->queue[scheduler->size] = coder_id;
	if (strcmp(scheduler->name, "fifo") == 0)
		scheduler->order[scheduler->size] = scheduler->counter++;
	else if (strcmp(scheduler->name, "edf") == 0)
	{
		c = &scheduler->coders[coder_id - 1];
		scheduler->order[scheduler->size]
			= c->last_compile_time + c->time_to_burnout;
	}
	if (strcmp(scheduler->name, "fifo") == 0)
		heapify_up_fifo(scheduler, scheduler->size);
	else if (strcmp(scheduler->name, "edf") == 0)
		heapify_up_edf(scheduler, scheduler->size);
	scheduler->size++;
	return (0);
}

int	heap_pop(t_scheduler *scheduler)
{
	int	top;

	top = 0;
	if (scheduler->size > 0)
	{
		top = scheduler->queue[0];
		scheduler->queue[0] = scheduler->queue[scheduler->size - 1];
		scheduler->order[0] = scheduler->order[scheduler->size - 1];
		scheduler->size--;
		if (strcmp(scheduler->name, "fifo") == 0)
			heapify_down_fifo(scheduler, 0);
		else if (strcmp(scheduler->name, "edf") == 0)
			heapify_down_edf(scheduler, 0);
	}
	return (top);
}

int	heap_peek(t_scheduler *scheduler)
{
	int	top;

	top = 0;
	if (scheduler->size > 0)
		top = scheduler->queue[0];
	return (top);
}
