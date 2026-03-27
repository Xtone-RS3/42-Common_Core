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


typedef struct s_config
{
	int		number_of_coders; // num_of_philos;
	int		number_of_compiles_required; // num_times_to_eat;
	size_t	dongle_cooldown; // what does the CD stand for?
	int		number_of_compiles_req; // req meals
	size_t	base_burnout_time;
	size_t	base_compile_time;
	size_t	base_debug_time;
	size_t	base_refactor_time;
	char	*scheduler; // forsenAlright
}			t_config;

typedef struct s_coders
{
	pthread_t		thread;
	int				id;
	int				compiling; // eating
	int				number_of_compiles; // meals_eaten;
	size_t			last_compile_time; // last_meal;
	size_t			time_to_burnout; // time_to_die;
	size_t			time_to_compile; // time_to_eat;
	size_t			time_to_debug; // time_to_sleep;
	size_t			time_to_refactor; // ????
	size_t			start_time;
	int				*burnt_out; // *dead;
	pthread_mutex_t	*r_dongle; // *r_fork;
	pthread_mutex_t	*l_dongle; // *l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*compile_lock; // *meal_lock;
	t_config		*config;
}					t_coders;


typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	compile_lock; // meal_lock;
	pthread_mutex_t	write_lock;
	t_coders		*coders; // *philos;
}					t_program;

int	ft_usleep(size_t milliseconds);

#endif