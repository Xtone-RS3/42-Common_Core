/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:47:07 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:58:26 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	heapify_up_edf(t_scheduler *scheduler, int i)
{
	int	parent;

	while (i > 0)
	{
		parent = (i - 1) / 2;
		if (scheduler->order[i] > scheduler->order[parent]
			|| (scheduler->order[i] == scheduler->order[parent]
				&& scheduler->queue[i] < scheduler->queue[parent]))
		{
			break ;
		}
		swap_nodes(scheduler, i, parent);
		i = parent;
	}
}

void	heapify_down_edf(t_scheduler *scheduler, int i)
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
			&& (scheduler->order[left] < scheduler->order[smallest]
				|| (scheduler->order[left] == scheduler->order[smallest]
					&& scheduler->queue[left] < scheduler->queue[smallest])))
			smallest = left;
		if (right < scheduler->size
			&& (scheduler->order[right] < scheduler->order[smallest]
				|| (scheduler->order[right] == scheduler->order[smallest]
					&& scheduler->queue[right] < scheduler->queue[smallest])))
			smallest = right;
		if (smallest == i)
			break ;
		swap_nodes(scheduler, i, smallest);
		i = smallest;
	}
}
