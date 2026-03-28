/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:04:16 by username          #+#    #+#             */
/*   Updated: 2026/03/23 16:46:40 by gasoares         ###   ########.fr       */
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

int	dead_loop(t_coders *coders)
{
	// printf("->burnt_out loop: %i\n", *coders->burnt_out);
	pthread_mutex_lock(coders->dead_lock);
	if (*coders->burnt_out == 1)
		return (pthread_mutex_unlock(coders->dead_lock), 1);
	pthread_mutex_unlock(coders->dead_lock);
	return (0);
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

int	argv_check(int argc, char **argv)
{
	if (argc <= 8)
		return (0);
	if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0 || atoi(argv[4]) <= 0 || atoi(argv[5]) <= 0 || atoi(argv[7]) < 0)
		return (0);
	return (1);
}

void	think(t_coders *coders)
{
	print_message("is refactoring", coders, coders->id);
	ft_usleep(coders->time_to_refactor);
}

// Dream routine funtion

void	dream(t_coders *coders)
{
	print_message("is debugging", coders, coders->id);
	ft_usleep(coders->time_to_debug); //time_to_refactor
}

// Eat routine funtion

void	eat(t_coders *coders)
{
	pthread_mutex_lock(coders->r_dongle);
	// printf(">%d last time is: %zu\n", coders->id, coders->last_compile_time);
	print_message("has taken a dongle", coders, coders->id);
	// printf("eat this: %d\n", coders->config->number_of_coders);
	if (coders->config->number_of_coders == 1) //easy check for solo dev
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
	ft_usleep(coders->time_to_compile); //->time_to_compile // coders->config->base_compile_time
	coders->compiling = 0;
	// pthread_mutex_unlock(coders->l_dongle);//maybe remove this from here and put it on dongleCD 💿
	// pthread_mutex_unlock(coders->r_dongle);
}


void	dongle_cd(t_coders *coders)
{
	ft_usleep(coders->config->dongle_cooldown);
	pthread_mutex_unlock(coders->l_dongle);
	pthread_mutex_unlock(coders->r_dongle);
}

int is_my_turn(t_coders *coders)
{
	t_scheduler *s = &coders->config->scheduler;
	int id = coders->id - 1;

	// for (int i = 0; i < s->size / 2; i++)
	for (int i = 0; i < s->size; i++)
	{
		if (s->queue[i] == id)
			return (1);
	}
	return (0);
}

void pop_current(t_scheduler *scheduler)
{
	int i;

	if (scheduler->size <= 0)
		return;

	for (i = 0; i < scheduler->size - 1; i++)
		scheduler->queue[i] = scheduler->queue[i + 1];
}

void push_back_or_reorder(t_scheduler *scheduler, int id)
{
	scheduler->queue[scheduler->size - 1] = id;
}

void push_back_or_reorder_edf(t_coders *coders, int id)
{
	int		i;
	size_t	new_deadline;
	size_t	d;
	int		qd_coder_id;

	i = coders->config->scheduler.size - 2;
	new_deadline = coders[id].last_compile_time + coders[id].time_to_burnout;
	while (i >= 0)
	{
		qd_coder_id = coders->config->scheduler.queue[i];
		d = coders[qd_coder_id].last_compile_time + coders[qd_coder_id].time_to_burnout;
		if (d < new_deadline)
			break;
		if (d == new_deadline && qd_coder_id > id)
			break;
		coders->config->scheduler.queue[i + 1] = coders->config->scheduler.queue[i];
		i--;
	}
	coders->config->scheduler.queue[i + 1] = id;
}

void wait_turn(t_coders *coders)
{
	pthread_mutex_lock(&coders->config->scheduler.lock);

	while (!is_my_turn(coders))
		pthread_cond_wait(&coders->config->scheduler.cond,
							&coders->config->scheduler.lock);

	pthread_mutex_unlock(&coders->config->scheduler.lock);
}

void finish_turn(t_coders *coders)
{
	int	current;

	current = coders->config->scheduler.queue[0];
	pthread_mutex_lock(&coders->config->scheduler.lock);
	pop_current(&coders->config->scheduler);          // remove self from queue
	if (strcmp(coders->config->scheduler.name, "fifo") == 0)
	{
		// printf("fifo: %d\n", current);
		push_back_or_reorder(&coders->config->scheduler, current); // FIFO or EDF logic
	}
	else if (strcmp(coders->config->scheduler.name, "edf") == 0)
	{
		// printf("edf: %d\n", current);
		push_back_or_reorder_edf(coders, current); // FIFO or EDF logic
	}
	pthread_cond_broadcast(&coders->config->scheduler.cond);
	pthread_mutex_unlock(&coders->config->scheduler.lock);
}

// Thread routine

void	*coders_routine(void *pointer)
{
	t_coders	*coders;
	// int	heap[] = {1, 3, 5, 2, 4, 6};
	// int	curr = 0;

	coders = (t_coders *)pointer;
	//vvvvv is NOT having id%2 (or anything at all)fifo????
	// if (coders->id % 2 == 0)
	// 	ft_usleep(1);
	// pthread_mutex_lock(coders->heap);
	// if (heap[curr] != coders->id)
	// {
	// 	printf("waiting on %d\n", coders->id);
	// 	ft_usleep(1);
	// }
	// printf(">coder grabbing is: %d\n", coders->id);
	// printf(">curr: %d\n", curr);
	while (!dead_loop(coders))
	{
		wait_turn(coders);
		// ft_usleep(1); //needed?
		eat(coders);
		finish_turn(coders);
		// ft_usleep(1);
		dongle_cd(coders);
		dream(coders);
		think(coders);
	}
	// curr += 1;
	// pthread_mutex_unlock(coders->heap);
	return (pointer);
}

void	init_program(t_program *program, t_coders *coders)
{
	program->dead_flag = 0;
	program->coders = coders;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->compile_lock, NULL);
	// pthread_mutex_init(&program->scheduler_lock, NULL);
	// pthread_mutex_init(&coders->config->scheduler.lock, NULL);//forsenAlright? or forsenInsane?
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

void	init_coders(t_coders *coders, t_program *program, pthread_mutex_t *dongles,
		char **argv, t_config *config)
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
		// coders[n_coders].scheduler_lock = &program->scheduler_lock;
		coders[n_coders].burnt_out = &program->dead_flag;
		coders[n_coders].l_dongle = &dongles[n_coders];
		coders[n_coders].start_time = get_current_time();
		coders[n_coders].last_compile_time = get_current_time();
		if (n_coders == 0)
			coders[n_coders].r_dongle = &dongles[atoi(argv[1]) - 1];
		else
			coders[n_coders].r_dongle = &dongles[n_coders - 1];
		coders[n_coders].config = config;
		n_coders += 1;
	}
	// printf("config: %p\n", (void *)config);
	// printf("assigned: %p\n", (void *)coders->config);
}

void init_scheduler(t_scheduler *scheduler, int n) //, t_coders *coders, int mode
{
	scheduler->queue = malloc(sizeof(int) * n);
	scheduler->size = n;
	scheduler->capacity = n;
	// scheduler->coders = coders;
	// scheduler->mode = mode; //forsenNotLookingAtYou for now

	for (int i = 0; i < n; i++)
		scheduler->queue[i] = i;

	pthread_mutex_init(&scheduler->lock, NULL);
	pthread_cond_init(&scheduler->cond, NULL);
}

void	init_config(t_config *config, char **argv)
{
	config->number_of_coders = atoi(argv[1]);
	config->base_burnout_time = atoi(argv[2]);
	config->base_compile_time = atoi(argv[3]);
	config->base_debug_time = atoi(argv[4]);
	config->base_refactor_time = atoi(argv[5]);
	config->number_of_compiles_required = atoi(argv[6]);
	config->dongle_cooldown = atoi(argv[7]);
	config->scheduler.name = argv[8];
}

void	destory_all(char *str, t_program *program, pthread_mutex_t *dongles, t_config *config)
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
	// pthread_mutex_destroy(&program->scheduler_lock);
	pthread_mutex_destroy(&config->scheduler.lock);
	// printf("destroy this: %d\n", config->number_of_coders);
	while (i < config->number_of_coders)
	{
		pthread_mutex_destroy(&dongles[i]);
		i++;
	}
}

// Checks if the philosopher is burnt_out

int	coder_dead(t_coders *coders, size_t time_to_burnout)
{
	pthread_mutex_lock(coders->compile_lock);
	if (get_current_time() - coders->last_compile_time >= time_to_burnout
		&& coders->compiling == 0)
		return (pthread_mutex_unlock(coders->compile_lock), 1);
	pthread_mutex_unlock(coders->compile_lock);
	return (0);
}

// Check if any philo died

int	check_if_dead(t_coders *coders)
{
	int	i;

	i = 0;
	// printf("check burnt_out this: %d\n", coders->config->number_of_coders);
	while (i < coders->config->number_of_coders)
	{
		if (coder_dead(&coders[i], coders[i].time_to_burnout)) //coders[i].config->base_burnout_time
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

// Checks if all the philos ate the num_of_meals

int	check_if_all_ate(t_coders *coders)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (coders->config->number_of_compiles_required == -1) //coders[0].config.number_of_compiles_required
		return (0);
	while (i < coders->config->number_of_coders)
	{
		pthread_mutex_lock(coders[i].compile_lock);
		if (coders[i].number_of_compiles >= coders->config->number_of_compiles_required)
			finished_eating++;
		pthread_mutex_unlock(coders[i].compile_lock);
		i++;
	}
	if (finished_eating == coders->config->number_of_coders)
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

int	thread_create(t_program *program, pthread_mutex_t *dongles, t_config *config)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->coders) != 0)
		destory_all("Thread creation error", program, dongles, config);
	i = 0;
	printf("thread create this: %d\n", config->number_of_coders);
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

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}


//maybe just:
//at start, run this argv[1] times and build a heap argv[1] big, already sorted by the odd/even thing
//then, after that heap is empty, load it again argv[1] times, and so on
//the hard part here is making sure the first load is math based, and therefore, good...

//remember that you need to reverse the load order during eval
// void	edf_schedule(t_coders *coders) //maybe return the ID that needs to go next
// {

// }

int	main(int argc, char **argv)
{
	int				n_coders;
	t_program		program;
	t_config		config;
	t_coders		*coders;
	pthread_mutex_t	*dongles;

	n_coders = 0;
	// number_of_coders time_to_burnout time_to_compile time_to_debug time_to_refactor number_of_compiles_required dongle_cooldown scheduler
	if (argv_check(argc, argv) == 0)
		return (printf("wrong input lol\n"), 1);
	coders = calloc(atoi(argv[1]) + 1, sizeof(t_coders));
	dongles = calloc(atoi(argv[1]) + 1, sizeof(pthread_mutex_t));
	init_config(&config, argv);
	init_program(&program, coders);
	init_dongles(dongles, atoi(argv[1]));
	init_coders(coders, &program, dongles, argv, &config);
	init_scheduler(&config.scheduler, atoi(argv[1]));
	//<---   heap-ing goes here
	// for (int i = 0; i < atoi(argv[1]); i++)
	// {
	// 	config.scheduler.queue[i] = i;
	// 	printf("queue[%d]: %d\n", i, i);
	// }
	for (int i = 0; i < atoi(argv[1]); i++)
	{
		config.scheduler.queue[i] = atoi(argv[1])-i-1;
		printf("queue[%d]: %d\n", i, atoi(argv[1])-i-1);
	}
	thread_create(&program, dongles, &config);
	destory_all(NULL, &program, dongles, &config);

	free(program.coders);
	free(dongles);
	free(config.scheduler.queue);
	return (0);
}
