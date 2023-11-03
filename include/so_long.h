/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:24:34 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 11:28:10 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h> 
# include <fcntl.h>

# define ESC				53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_UP				126
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define TRUE				1
# define FALSE				0
# define ROB_PATHA			"./textures/characters/robber64a.xpm"
# define ROB_PATHD			"./textures/characters/robber64d.xpm"
# define C_PATH				"./textures/collectables/money_bag.xpm"
# define W_PATH				"./textures/wall/wall64.xpm"
# define D_PATH				"./textures/wall/door64.xpm"
# define F_PATH				"./textures/wall/floor64.xpm"
# define RED				"\033[1;31m"
# define END				"\x1b[0m"
# define CYAN				"\033[1;36m"
# define BHYEL 				"\e[1;93m"

typedef struct s_sprite
{
	int	x;
	int	y;
	int	x0;
	int	y0;
}				t_sprite;

typedef struct s_player
{
	void		*player_a;
	void		*player_d;
	t_sprite	spr;
	int			step;
	int			dir;
}				t_player;

typedef struct s_mlx_data
{
	t_player	plyr;
	void		*ptr;
	void		*win;
	char		*map;
	char		**map1;
	char		**map2;
	int			n_collectables;
	int			height;
	int			width;
	void		*wall;
	void		*floor;
	void		*exit;
	void		*coin;
	void		*counter;
}				t_mlx_data;

int		handle_input(int keycode, t_mlx_data *data);
int		ft_close(t_mlx_data *win, int err);
void	init_map(t_mlx_data *data);
void	ft_error(char *msg, int err, t_mlx_data *d);
void	ft_exit(char *msg, int err, t_mlx_data *d);
void	ft_free(char **a);
void	check_map_comps(t_mlx_data *d);
void	check_map_form(t_mlx_data *d);
void	check_perimeter(t_mlx_data *d);
void	check_enough_comp(t_mlx_data *d);
void	ft_check_ways(t_mlx_data *d);
void	check_extension(t_mlx_data *d);
void	enough_p(t_mlx_data *d);
void	enough_e(t_mlx_data *d);
void	enough_c(t_mlx_data *d);
int		is_1(char c);
int		is_0(char c);
int		is_c(char c);
int		is_e(char c);
int		is_p(char c);
int		draw_map(t_mlx_data *d);
void	draw_floor(t_mlx_data *d);
void	draw_collectables(t_mlx_data *d);
void	draw_walls(t_mlx_data *d);
void	draw_plyr(t_mlx_data *d);
void	find_player(t_mlx_data *d);
int		map_height(char **m);
void	ft_move_x(t_mlx_data *data, int movement);
void	ft_move_y(t_mlx_data *data, int movement);
void	ft_print_steps(t_mlx_data *data);

#endif
