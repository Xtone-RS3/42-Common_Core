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
			"images/Clueless.xpm", &w, &h);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"images/Aware.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"images/sadE.xpm", &w, &h);
}

void	redraw(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
}

void	try_move(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	target;

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
	else if (g->map[y][x] == 'E' && g->score == g->max_score)
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit_open, x * g->t_s, y * g->t_s);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win,
			g->img_exit, x * g->t_s, y * g->t_s);
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	char	*score_bar;

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
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				game->max_score += 1;
			}
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

int	main(int argc, char **argv)
{
	t_game	game;

	game.mlx = mlx_init();
	load_images(&game);
	map_open_and_row(argc, argv, &game);
	find_player(&game);
	find_score(&game);
	mlx_key_hook(game.win, key_handler, &game);
	draw_map(&game);
	mlx_loop(game.mlx);
}
