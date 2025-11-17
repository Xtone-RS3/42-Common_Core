/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:40:19 by gasoares          #+#    #+#             */
/*   Updated: 2025/11/15 11:40:20 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);//now: 1763390678252
}

long	sadE(long boot_time, t_game *game)
{
	game->rng_seed = (boot_time * 1664526) % 2147483647;
	return ((int)game->rng_seed);
}

void	load_images_cont7(t_game *game, int w, int h)
{
	game->img_exit_trans[75] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[76] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[77] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[78] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[79] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[80] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[81] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[82] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[83] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[84] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_angrE = mlx_xpm_file_to_image(game->mlx,
			"images/angrE.xpm", &w, &h);
	game->img_BB_vision = mlx_xpm_file_to_image(game->mlx,
			"images/forsenEmote2_2.xpm", &w, &h);
}

void	load_images_cont6(t_game *game, int w, int h)
{
	game->img_exit_trans[63] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[64] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[65] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[66] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[67] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[68] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[69] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[70] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[71] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[72] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[73] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[74] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_58_delay-0.4s.xpm", &w, &h);
	load_images_cont7(game, w, h);
}

void	load_images_cont5(t_game *game, int w, int h)
{
	game->img_exit_trans[51] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_47_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[52] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_48_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[53] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_49_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[54] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_50_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[55] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_51_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[56] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_52_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[57] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_53_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[58] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_54_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[59] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_55_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[60] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_56_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[61] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	game->img_exit_trans[62] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_57_delay-0.4s.xpm", &w, &h);
	load_images_cont6(game, w, h);
}

void	load_images_cont4(t_game *game, int w, int h)
{
	game->img_exit_trans[39] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_36_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[40] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_37_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[41] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_38_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[42] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_39_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[43] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_40_delay-0.1s.xpm", &w, &h);
	game->img_exit_trans[44] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_40_delay-0.1s.xpm", &w, &h);
	game->img_exit_trans[45] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_41_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[46] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_42_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[47] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_43_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[48] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_44_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[49] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_45_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[50] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_46_delay-0.05s.xpm", &w, &h);
	load_images_cont5(game, w, h);
}

void	load_images_cont3(t_game *game, int w, int h)
{
	game->img_exit_trans[27] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_24_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[28] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_25_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[29] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_26_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[30] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_27_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[31] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_28_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[32] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_29_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[33] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_30_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[34] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_31_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[35] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_32_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[36] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_33_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[37] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_34_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[38] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_35_delay-0.05s.xpm", &w, &h);
	load_images_cont4(game, w, h);
}

void	load_images_cont2(t_game *game, int w, int h)
{
	game->img_exit_trans[15] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_12_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[16] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_13_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[17] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_14_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[18] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_15_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[19] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_16_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[20] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_17_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[21] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_18_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[22] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_19_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[23] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_20_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[24] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_21_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[25] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_22_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[26] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_23_delay-0.05s.xpm", &w, &h);
	load_images_cont3(game, w, h);
}

void	load_images_cont1(t_game *game, int w, int h)
{
	game->img_exit_trans[3] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_00_delay-0.2s.xpm", &w, &h);
	game->img_exit_trans[4] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_01_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[5] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_02_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[6] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_03_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[7] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_04_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[8] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_05_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[9] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_06_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[10] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_07_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[11] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_08_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[12] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_09_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[13] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_10_delay-0.05s.xpm", &w, &h);
	game->img_exit_trans[14] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_11_delay-0.05s.xpm", &w, &h);
	load_images_cont2(game, w, h);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	game->t_s = 64;
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"images/forsenMaxLevel.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"images/forsenEmote.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"images/forsenE.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_00_delay-0.2s.xpm", &w, &h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_59_delay-0.4s.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"images/sadE.xpm", &w, &h);
	game->img_exit_trans[0] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_00_delay-0.2s.xpm", &w, &h);
	game->img_exit_trans[1] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_00_delay-0.2s.xpm", &w, &h);
	game->img_exit_trans[2] = mlx_xpm_file_to_image(game->mlx,
			"images/aware_xpm/frame_00_delay-0.2s.xpm", &w, &h);
	load_images_cont1(game, w, h);
}

void	redraw(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
}

void	animate(t_game *game)
{
	static long	last_time;
	long		now;

	now = get_time_ms();
	if (game->score != game->max_score)
		return ;
	if (now - last_time >= (long)50 && game->gif_s == 0)
	{
		last_time = now;
		game->curr_frame++;
		if (game->curr_frame >= 60)
		{
			game->curr_frame = 59;
			game->gif_s = 1;
		}
	}
}

void	find_BB_xy(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	game->BB_xy = malloc(sizeof(t_BB) * game->BB_n);
	if (!game->BB_xy)
		return ;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'B')
			{
				game->BB_xy[i].x = x;
				game->BB_xy[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	BB_attempt(t_game *g, int neg, int i, int attempts)
{
	char	target;

	if (attempts <= 0)
		return ;
	if (sadE(g->rng_seed, g) % 2 == 1)
		neg = -1;
	g->BB_xy[i].x_move = g->BB_xy[i].x + (sadE(g->rng_seed, g) % 2) * neg;
	if (sadE(g->rng_seed, g) % 2 == 1)
		neg = -1;
	g->BB_xy[i].y_move = g->BB_xy[i].y + (sadE(g->rng_seed, g) % 2) * neg;
	target = g->map[g->BB_xy[i].y_move][g->BB_xy[i].x_move];
	ft_printf("g->BB_xy[%d].x_move: %d\ng->BB_xy[%d].y_move: %d\n", i, g->BB_xy[i].x_move, i, g->BB_xy[i].y_move);
	if (target == '0')
		g->map[g->BB_xy[i].y_move][g->BB_xy[i].x_move] = 'A';
	else
		return (BB_attempt(g, neg, i, attempts - 1));
}

void	BB_looking(t_game *g)
{
	int		neg;
	int		i;

	i = 0;
	neg = 1;
	printf("=========================\n");
	printf("BB_n: %d\n", g->BB_n);
	while (i < g->BB_n)
	{
		BB_attempt(g, neg, i, 5);
		
		// else
		// 	return ;
		i++;
	}
}

void	BB_move(t_game *g)
{
	char	target;
	int		i;

	i = 0;
	while (i < g->BB_n)
	{
		target = g->map[g->BB_xy[i].y_move][g->BB_xy[i].x_move];
		if (target == 'A')
		{
			g->map[g->BB_xy[i].y][g->BB_xy[i].x] = '0';
			g->map[g->BB_xy[i].y_move][g->BB_xy[i].x_move] = 'B';
			g->BB_xy[i].y = g->BB_xy[i].y_move;
			g->BB_xy[i].x = g->BB_xy[i].x_move;
		}
		// else
		// 	return ;
		i++;
	}
	// g->player_x = new_x;
	// g->player_y = new_y;
	// g->walked += 1;
	//ft_printf("%d\n", g->walked);
	//redraw(g);
}

void	try_move(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	BB_move(game);
	BB_looking(game);
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'E' && game->score == game->max_score)
		exit(0);
	else if (target == 'E')
		return ;
	if (target == 'C')
		game->score += 1;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->walked += 1;
	ft_printf("%d\n", game->walked);
	redraw(game);
}

void	stupid_fucking_norminette2(t_game *g, int y, int x)
{
	if (g->map[y][x] == 'B')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_angrE, x * g->t_s, y * g->t_s);
	else if (g->map[y][x] == 'A')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_BB_vision, x * g->t_s, y * g->t_s);
	
}

void	stupid_fucking_norminette(t_game *g, int y, int x)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_wall, x * g->t_s, y * g->t_s);
	else
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_floor, x * g->t_s, y * g->t_s);
	if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_player, x * g->t_s, y * g->t_s);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_collectible, x * g->t_s, y * g->t_s);
	else if (g->map[y][x] == 'E' && g->gif_s == 1)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_trans[84], x * g->t_s, y * g->t_s);
	else if (g->map[y][x] == 'E' && g->score == g->max_score && g->gif_s == 0)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_trans[g->curr_frame], x * g->t_s, y * g->t_s);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_trans[0], x * g->t_s, y * g->t_s);
	else
		stupid_fucking_norminette2(g, y, x);
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	char	*score_bar;

	//ft_printf("BB_1:\nx: %d\ny: %d\n", g->BB_xy[0].x, g->BB_xy[0].y);
	//ft_printf("BB_2:\nx: %d\ny: %d\n", g->BB_xy[1].x, g->BB_xy[1].y);
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			stupid_fucking_norminette(g, y, x);
			x++;
		}
		y++;
	}
	score_bar = ft_strjoin("score ", ft_itoa(g->score));
	mlx_string_put(g->mlx, g->win, 0, 10, 0xffffff, score_bar);
}

void	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	find_score(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->score = 0;
	game->max_score = 0;
	game->walked = 0;
	game->frame = 0;
	game->curr_frame = 0;
	game->gif_s = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->max_score += 1;
			x++;
		}
		y++;
	}
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 'w')
		try_move(game, 0, -1);
	if (keycode == 's')
		try_move(game, 0, 1);
	if (keycode == 'a')
		try_move(game, -1, 0);
	if (keycode == 'd')
		try_move(game, 1, 0);
	return (0);
}

void	map_assign(int rows, t_game *g, char *to_open)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(to_open, O_RDONLY);
	while (i < rows)
	{
		j = 0;
		line = get_next_line(fd);
		g->map[i] = ft_calloc(sizeof(char *), (ft_strlen(line) + 1));
		if (!g->map[i])
			free(g->map);
		while (line[j])
		{
			if (line[j] == 'B')
				g->BB_n++;
			g->map[i][j] = line[j];
			j++;
		}
		i++;
		free(line);
	}
	g->win = mlx_new_window(g->mlx, (j - 1) * g->t_s, rows * g->t_s, to_open);
}

void	map_open_and_row(int argc, char **argv, t_game *game)
{
	int		fd;
	int		rows;
	char	*line;
	char	*to_open;

	rows = 0;
	if (argc > 2)
		ft_printf("Error\nput map.ber in you fucking idiot");
	else if (argc == 2)
		to_open = ft_strjoin("maps/", argv[1]);
	else
		to_open = "maps/map2.ber";
	fd = open(to_open, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_calloc(sizeof(char *), (rows + 1));
	if (!game->map)
		return ;
	map_assign(rows, game, to_open);
}

int	game_loop(t_game *game)
{
	animate(game);
	draw_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.BB_n = 0;
	sadE(get_time_ms(), &game);
	game.mlx = mlx_init();
	game.img_exit_trans = ft_calloc(sizeof(void *), 85);
	load_images(&game);
	map_open_and_row(argc, argv, &game);
	find_player(&game);
	find_score(&game);
	mlx_key_hook(game.win, key_handler, &game);
	find_BB_xy(&game);
	BB_looking(&game);
	draw_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
}
