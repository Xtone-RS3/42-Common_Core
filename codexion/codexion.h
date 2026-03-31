/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:26:40 by gasoares          #+#    #+#             */
/*   Updated: 2026/03/31 11:57:45 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_coders	t_coders;

typedef struct s_cooldown_args
{
	pthread_mutex_t	*dongle;
	size_t			cooldown_ms;
}					t_cooldown_args;

typedef struct s_scheduler
{
	char			*name;
	int				*queue; // array of coder IDs
	int				*order;
	int				counter;
	int				size;
	int				capacity;
	pthread_mutex_t	lock;
	pthread_cond_t	cond;
	t_coders		*coders;
}					t_scheduler;

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
	int				compiling;
	int				number_of_compiles;
	size_t			last_compile_time;
	size_t			time_to_burnout;
	size_t			time_to_compile;
	size_t			time_to_debug;
	size_t			time_to_refactor;
	size_t			start_time;
	int				*burnt_out;
	pthread_mutex_t	*r_dongle;
	pthread_mutex_t	*l_dongle;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*compile_lock;
	t_config		*config;
}					t_coders;

typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	compile_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	scheduler_lock;
	t_coders		*coders;
}					t_program;

//routine
void	refactor(t_coders *coders);
void	debug(t_coders *coders);
void	compile(t_coders *coders);
void	*coders_routine(void *pointer);

//utils
size_t	get_current_time(void);
void	print_message(char *str, t_coders *coders, int id);
int		ft_usleep(size_t milliseconds);
void	swap_nodes(t_scheduler *s, int a, int b);

//init_one
void	init_program(t_program *program, t_coders *coders);
void	init_input(t_coders *coders, char **argv);
void	init_dongles(pthread_mutex_t *dongles, int coders_num);
void	init_coders(t_coders *coders, t_program *program,
			pthread_mutex_t *dongles, char **argv);
void	init_coders_cont(t_coders *coders, char **argv, t_config *config);

//init_two
void	init_scheduler(t_config *config, int n, t_coders *coders);
void	init_config(t_config *config, char **argv);

//arg_stuff
int		is_valid_scheduler(const char *s);
int		argv_check(int argc, char **argv);

//heap_n_fifo
void	heapify_up_fifo(t_scheduler *scheduler, int i);
void	heapify_down_fifo(t_scheduler *scheduler, int i);
int		heap_push(t_scheduler *scheduler, int coder_id);
int		heap_pop(t_scheduler *scheduler);
int		heap_peek(t_scheduler *scheduler);

//edf
void	heapify_up_edf(t_scheduler *scheduler, int i);
void	heapify_down_edf(t_scheduler *scheduler, int i);

//death_n_dongles
int		dead_loop(t_coders *coders);
void	*cooldown_thread(void *ptr);
void	start_dongle_cooldown(pthread_mutex_t *dongle, size_t cooldown_ms);
int		coder_dead(t_coders *coders, size_t time_to_burnout);
int		check_if_dead(t_coders *coders);

#endif