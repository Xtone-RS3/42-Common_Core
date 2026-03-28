/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:26:40 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/23 15:15:00 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
# include <sys/time.h>

// typedef struct s_task
// {
// 	int			id;
// 	int			deadline;
// }				t_task;

// typedef struct s_minheap
// {
// 	t_task	*arr;
// 	int		size;
// 	int		capacity;
// }			t_minheap;

// typedef struct s_my_heap
// {
// 	int			id;
// 	int			deadline;
// 	t_coders	coder;
// }				t_my_heap;

typedef struct s_scheduler
{
	char			*name;
	int				*queue; // array of coder IDs
	int				size;
	int				capacity;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
	// t_coders		*coders;
} 					t_scheduler;

typedef struct s_config
{
	int				number_of_coders; // number_of_coders;
	int				number_of_compiles_required; // number_of_compiles_required;
	size_t			dongle_cooldown; // what does the CD stand for?
	int				number_of_compiles_req; // req meals
	size_t			base_burnout_time;
	size_t			base_compile_time;
	size_t			base_debug_time;
	size_t			base_refactor_time;
	t_scheduler		scheduler;
}					t_config;

typedef struct s_coders
{
	pthread_t		thread;
	int				id;
	int				compiling; // compiling
	int				number_of_compiles; // number_of_compiles;
	size_t			last_compile_time; // last_compile_time;
	size_t			time_to_burnout; // time_to_burnout;
	size_t			time_to_compile; // time_to_compile;
	size_t			time_to_debug; // time_to_debug;
	size_t			time_to_refactor; // time_to_refactor;
	size_t			start_time;
	int				*burnt_out; // *burnt_out;
	pthread_mutex_t	*r_dongle; // *r_dongle;
	pthread_mutex_t	*l_dongle; // *l_dongle;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*compile_lock; // *compile_lock;
	// pthread_mutex_t	*scheduler_lock;
	t_config		*config;
}					t_coders;


typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	compile_lock; // compile_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	scheduler_lock;
	t_coders		*coders; // *philos;
	// t_scheduler		scheduler;
}					t_program;

int	ft_usleep(size_t milliseconds);

#endif