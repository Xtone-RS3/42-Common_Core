/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasoares <gasoares@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:11:49 by gasoares          #+#    #+#             */
/*   Updated: 2025/11/15 18:11:53 by gasoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include "mlx/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include "get_next_line/get_next_line.h"
#include <sys/time.h>

typedef struct s_BB {
	int	y;
	int	x;
	int	y_move;
	int	x_move;
}	t_BB;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	**img_exit_trans;
	void	**img_death;
	void	**img_win;
	void	*img_exit_open;
	void	*img_collectible;
	void	*img_angrE;
	void	*img_BB_vision;
	char	**map;
	int		t_s;
	int		player_x;
	int		player_y;
	int		BB_n;
	t_BB	*BB_xy;
	int		score;
	int		max_score;
	int		walked;
	int		frame;
	int		curr_frame;
	int		dead_frame;
	int		dead_gif;
	int		gif_s;
	long	rng_seed;
	int		dead;
}	t_game;





void load_images(t_game *game);
void redraw(t_game *game);
void try_move(t_game *game, int dx, int dy);
void draw_map(t_game *game);
void find_player(t_game *game);
int key_handler(int keycode, t_game *game);


#endif
