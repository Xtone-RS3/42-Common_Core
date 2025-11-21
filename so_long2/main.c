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

void	game_var_init(t_game *game, int argc, char **argv)
{
	game->bb_n = 0;
	game->dead = 0;
	game->dead_frame = 0;
	game->dead_gif = 0;
	game->won = 0;
	game->won_gif = 0;
	game->won_frame = 0;
	game->score = 0;
	game->max_score = 0;
	game->walked = 0;
	game->frame = 0;
	game->curr_frame = 0;
	game->gif_stop = 0;
	game->img_exit_trans = ft_calloc(sizeof(void *), 85);
	game->img_death = ft_calloc(sizeof(void *), 5);
	game->img_win = ft_calloc(sizeof(void *), 155);
	sade(get_time_ms(), game);
	game->mlx = mlx_init();
	load_images(game);
	map_open_and_row(argc, argv, game);
	find_player(game);
	find_score(game);
	find_bb_xy(game);
	bb_looking(game);
}

char	*img_name_gen(char *i)
{
	char	*hold;
	char	*result;

	hold = ft_strjoin("images/vibE/vibE_", i);
	result = ft_strjoin(hold, ".xpm");
	return (free(hold), result);
}

void	gigafree_cont(t_game *g, int i)
{
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	free(g->img_exit_trans);
	free(g->img_death);
	free(g->img_win);
	if (g->map)
	{
		while (g->map[i])
			free(g->map[i++]);
		free(g->map);
	}
	free(g->bb_xy);
	exit(0);
}

void	gigafree(t_game *g)
{
	int	i;

	i = 0;
	mlx_destroy_image(g->mlx, g->img_wall);
	mlx_destroy_image(g->mlx, g->img_floor);
	mlx_destroy_image(g->mlx, g->img_player);
	mlx_destroy_image(g->mlx, g->img_exit);
	mlx_destroy_image(g->mlx, g->img_exit_open);
	mlx_destroy_image(g->mlx, g->img_collectible);
	mlx_destroy_image(g->mlx, g->img_angre);
	mlx_destroy_image(g->mlx, g->img_bb_vision);
	while (i < 85)
		mlx_destroy_image(g->mlx, g->img_exit_trans[i++]);
	i = 0;
	while (i < 5)
		mlx_destroy_image(g->mlx, g->img_death[i++]);
	i = 0;
	while (i < 155)
		mlx_destroy_image(g->mlx, g->img_win[i++]);
	gigafree_cont(g, 0);
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000);
}

long	sade(long boot_time, t_game *game)
{
	game->rng_seed = (boot_time * 1664526) % 2147483647;
	return ((int)game->rng_seed);
}

void	load_images_cont8(t_game *game, int w, int h)
{
	int		i;
	char	*hold;
	char	*itoa_hold;

	i = 0;
	game->img_death[0] = mlx_xpm_file_to_image(game->mlx,
			"images/monkaE/monkaE1.xpm", &w, &h);
	game->img_death[1] = mlx_xpm_file_to_image(game->mlx,
			"images/monkaE/monkaE2.xpm", &w, &h);
	game->img_death[2] = mlx_xpm_file_to_image(game->mlx,
			"images/monkaE/monkaE3.xpm", &w, &h);
	game->img_death[3] = mlx_xpm_file_to_image(game->mlx,
			"images/monkaE/monkaE4.xpm", &w, &h);
	game->img_death[4] = mlx_xpm_file_to_image(game->mlx,
			"images/monkaE/monkaE5.xpm", &w, &h);
	while (i < 155)
	{
		itoa_hold = ft_itoa(i);
		hold = img_name_gen(itoa_hold);
		game->img_win[i] = mlx_xpm_file_to_image(game->mlx,
				hold, &w, &h);
		free(hold);
		free(itoa_hold);
		i++;
	}
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
	game->img_angre = mlx_xpm_file_to_image(game->mlx,
			"images/angrE.xpm", &w, &h);
	game->img_bb_vision = mlx_xpm_file_to_image(game->mlx,
			"images/forsenEmote2_2.xpm", &w, &h);
	load_images_cont8(game, w, h);
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
	game->tile_size = 64;
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

void	animate_win(t_game *game)
{
	static long	last_time;
	long		now;

	now = get_time_ms();
	if (game->won == 0)
		return ;
	if (now - last_time >= (long)35 && game->won_gif == 0)
	{
		last_time = now;
		game->won_frame++;
		if (game->won_frame >= 155)
		{
			game->won_frame = 154;
			game->won_gif = 1;
		}
	}
}

void	animate_death(t_game *game)
{
	static long	last_time;
	long		now;

	now = get_time_ms();
	if (game->dead == 0)
		return ;
	if (now - last_time >= (long)100 && game->dead_gif == 0)
	{
		last_time = now;
		game->dead_frame++;
		if (game->dead_frame >= 5)
		{
			game->dead_frame = 4;
			game->dead_gif = 1;
		}
	}
}

void	animate(t_game *game)
{
	static long	last_time;
	long		now;

	now = get_time_ms();
	if (game->score != game->max_score)
		return ;
	if (now - last_time >= (long)50 && game->gif_stop == 0)
	{
		last_time = now;
		game->curr_frame++;
		if (game->curr_frame >= 60)
		{
			game->curr_frame = 59;
			game->gif_stop = 1;
		}
	}
}

void	find_bb_xy(t_game *game)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	game->bb_xy = malloc(sizeof(t_BB) * game->bb_n);
	if (!game->bb_xy)
		return ;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'B')
			{
				game->bb_xy[i].x = x;
				game->bb_xy[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	bb_attempt(t_game *g, int i)
{
	char	target;
	int		dir_x;
	int		dir_y;
	int		rand;

	rand = sade(g->rng_seed, g) % 2;
	dir_x = (rand * 2 - 1) * sade(g->rng_seed, g) % 2;
	g->bb_xy[i].x_move = g->bb_xy[i].x + dir_x;
	rand = sade(g->rng_seed, g) % 2;
	dir_y = (rand * 2 - 1) * sade(g->rng_seed, g) % 2;
	g->bb_xy[i].y_move = g->bb_xy[i].y + dir_y;
	target = g->map[g->bb_xy[i].y_move][g->bb_xy[i].x_move];
	if (target == '0')
		g->map[g->bb_xy[i].y_move][g->bb_xy[i].x_move] = 'A';
	else if (target == '1')
		return (bb_attempt(g, i));
}

void	bb_looking(t_game *g)
{
	int		i;

	i = 0;
	while (i < g->bb_n)
	{
		bb_attempt(g, i);
		i++;
	}
}

void	bb_move(t_game *g)
{
	char	target;
	int		i;

	i = 0;
	while (i < g->bb_n)
	{
		target = g->map[g->bb_xy[i].y_move][g->bb_xy[i].x_move];
		if (target == 'A')
		{
			g->map[g->bb_xy[i].y][g->bb_xy[i].x] = '0';
			g->map[g->bb_xy[i].y_move][g->bb_xy[i].x_move] = 'B';
			g->bb_xy[i].y = g->bb_xy[i].y_move;
			g->bb_xy[i].x = g->bb_xy[i].x_move;
		}
		i++;
	}
}

void	actual_movement(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->walked += 1;
	if (game->dead == 0)
	{
		bb_move(game);
		bb_looking(game);
	}
	ft_printf("%d\n", game->walked);
	redraw(game);
}

int	target_logic(t_game *game, char target)
{
	if (target == '1')
		return (0);
	else if (target == 'E' && game->score == game->max_score)
		return (game->won = 1, 1);
	else if (target == 'E')
		return (0);
	else if (target == 'C')
		return (game->score += 1, 1);
	else if (target == 'A' || target == 'B')
	{
		if (target == 'A')
			bb_move(game);
		return (game->dead = 1, 0);
	}
	else
		return (1);
}

void	try_move(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	target = game->map[new_y][new_x];
	if (target_logic(game, target) == 1)
		actual_movement(game, new_x, new_y);
}

void	silly_norminette2(t_game *g, int y, int x)
{
	if (g->map[y][x] == 'B')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_angre, x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'A')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_bb_vision, x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'P' && g->dead == 1)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_death[g->dead_frame], x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'P' && g->won == 1 && g->won_gif == 0)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_win[g->won_frame], x * g->tile_size, y * g->tile_size);
}

void	silly_norminette(t_game *g, int y, int x)
{
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_wall, x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == '0')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_floor, x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'P' && g->dead != 1 && g->won == 0)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_player, x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_collectible, x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'E' && g->gif_stop == 1)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_trans[84], x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'E' && g->score == g->max_score && g->gif_stop == 0)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_trans[g->curr_frame], x * g->tile_size, y * g->tile_size);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_trans[0], x * g->tile_size, y * g->tile_size);
	else
		silly_norminette2(g, y, x);
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	char	*score_bar;
	char	*score_hold;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			silly_norminette(g, y, x);
			x++;
		}
		y++;
	}
	score_hold = ft_itoa(g->score);
	score_bar = ft_strjoin("score ", score_hold);
	mlx_string_put(g->mlx, g->win, 0, 10, 0xffffff, score_bar);
	free(score_hold);//turn all this into an image
	free(score_bar);
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

int	key_handler(int key, t_game *game)
{
	if (key == 65307)
		gigafree(game);
	if (game->dead == 0 && game->won == 0)
	{
		if (key == 'w')
			try_move(game, 0, -1);
		if (key == 's')
			try_move(game, 0, 1);
		if (key == 'a')
			try_move(game, -1, 0);
		if (key == 'd')
			try_move(game, 1, 0);
	}
	else if (game->dead_gif == 1 || game->won == 1)
	{
		if (key == 'w' || key == 's' || key == 'a' || key == 'd')
			gigafree(game);
	}
	return (0);
}

void	map_assign_cont(int rows, t_game *g, char *to_open, int j)
{
	g->win = mlx_new_window(g->mlx, (j - 1) * g->tile_size, rows * g->tile_size, to_open);
	get_next_line(-2);
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
		j = -1;
		line = get_next_line(fd);
		g->map[i] = ft_calloc(sizeof(char *), (ft_strlen(line) + 1));
		if (!g->map[i])
			free(g->map);
		while (line[++j])
		{
			if (line[j] == 'B')
				g->bb_n++;
			g->map[i][j] = line[j];
		}
		free(line);
		i++;
	}
	map_assign_cont(rows, g, to_open, j);
	close(fd);
}

void	map_open_and_row_cont(t_game *game, int rows, char *to_open)
{
	game->map = ft_calloc(sizeof(char *), (rows + 1));
	if (!game->map)
		return (free(to_open));
	map_assign(rows, game, to_open);
	free(to_open);
}

char	*ft_strjoin_s_l(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[j])
	{
		result[j] = s1[j];
		j++;
	}
	while (s2[i])
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s2);
	return (result);
}

char	*arg_logic(char *input)
{
	if (ft_strnstr(input, ".ber", ft_strlen(input)) == NULL)
		return (ft_strjoin_s_l("maps/", ft_strjoin(input, ".ber")));
	return (ft_strjoin("maps/", input));
}

void	map_open_and_row(int argc, char **argv, t_game *game)
{
	int		fd;
	int		rows;
	char	*line;
	char	*to_open;

	rows = 0;
	if (argc == 2)
		to_open = arg_logic(argv[1]);
	else
		to_open = ft_strjoin("maps/map2.ber", "");
	ft_printf("Opening file: %s\n", to_open);
	fd = open(to_open, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map_open_and_row_cont(game, rows, to_open);
}

int	game_loop(t_game *game)
{
	animate_win(game);
	animate_death(game);
	animate(game);
	if ((game->dead == 1 && game->dead_gif == 0)
		|| (game->score == game->max_score && game->gif_stop == 0)
		|| (game->won == 1 && game->won_gif == 0))
	{
		draw_map(game);
	}
	if (game->dead_gif == 1)
		mlx_string_put(game->mlx, game->win, game->tile_size * game->player_x,
			game->tile_size * game->player_y, 0xffffff, "GAME OVER!");
	if (game->won == 1)
		mlx_string_put(game->mlx, game->win, game->tile_size * game->player_x,
			game->tile_size * game->player_y, 0xffffff, "YOU WIN!");
	usleep(16000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2)
		return (ft_printf("That's a lot of arguments man, try only 1!\n"), 1);
	game_var_init(&game, argc, argv);
	if (game.dead != 1 || game.dead_gif == 1)
		mlx_key_hook(game.win, key_handler, &game);
	draw_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	// gigafree(&game); //is this needed here? i doubt it
}
