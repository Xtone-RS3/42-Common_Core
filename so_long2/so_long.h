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
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include "get_next_line/get_next_line.h"
# include <sys/time.h>

typedef struct s_BB
{
	int	y;
	int	x;
	int	y_move;
	int	x_move;
}	t_BB;

typedef struct s_game
{
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
	void	*img_angre;
	void	*img_bb_vision;
	char	**map;
	int		t_s;
	int		player_x;
	int		player_y;
	int		bb_n;
	t_BB	*bb_xy;
	int		score;
	int		max_score;
	int		walked;
	int		frame;
	int		curr_frame;
	int		dead_frame;
	int		dead_gif;
	int		gif_end;
	long	rng_seed;
	int		dead;
	int		won;
	int		won_gif;
	int		won_frame;
}	t_game;


int		game_loop(t_game *game);
void	map_open_and_row(int argc, char **argv, t_game *game);
char	*arg_logic(char *input);
char	*ft_strjoin_s_l(char *s1, char *s2);
void	map_open_and_row_cont(t_game *game, int rows, char *to_open);
void	map_assign(int rows, t_game *g, char *to_open);
void	map_assign_cont(int rows, t_game *g, char *to_open, int j);
int		key_handler(int key, t_game *game);
void	find_score(t_game *game);
void	find_player(t_game *game);
void	draw_map(t_game *g);
void	silly_norminette(t_game *g, int y, int x);
void	silly_norminette2(t_game *g, int y, int x);
void	try_move(t_game *game, int dx, int dy);
int		target_logic(t_game *game, char target);
void	actual_movement(t_game *game, int new_x, int new_y);
void	bb_move(t_game *g);
void	bb_looking(t_game *g);
void	bb_attempt(t_game *g, int i);
void	find_bb_xy(t_game *game);
void	animate(t_game *game);
void	animate_death(t_game *game);
void	animate_win(t_game *game);
void	redraw(t_game *game);
void	load_images(t_game *game);
void	load_images_cont1(t_game *game, int w, int h);
void	load_images_cont2(t_game *game, int w, int h);
void	load_images_cont3(t_game *game, int w, int h);
void	load_images_cont4(t_game *game, int w, int h);
void	load_images_cont5(t_game *game, int w, int h);
void	load_images_cont6(t_game *game, int w, int h);
void	load_images_cont7(t_game *game, int w, int h);
void	load_images_cont8(t_game *game, int w, int h);
long	sade(long boot_time, t_game *game);
long	get_time_ms(void);
void	gigafree(t_game *g);
void	gigafree_cont(t_game *g, int i);
char	*img_name_gen(char *i);
void	game_var_init(t_game *game, int argc, char **argv);

#endif
