/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:46:37 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:49:33 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map1[++i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (is_p(d->map1[i][j]))
			{
				d->plyr.spr.x0 = i * 64;
				d->plyr.spr.y0 = j * 64;
			}
			j++;
		}
	}
}

char	**open_map(t_mlx_data *data)
{
	int		fd;
	char	*open_map;
	char	*lineal_map;
	char	**map;

	fd = open(data->map, O_RDONLY);
	if (fd == -1)
		ft_exit(RED"Error\nError while opening the map"END, 2, data);
	lineal_map = NULL;
	map = NULL;
	open_map = NULL;
	while (1)
	{
		open_map = get_next_line(fd);
		if (!open_map)
			break ;
		lineal_map = ft_strjoin_gnl(lineal_map, open_map);
		free(open_map);
	}
	free (open_map);
	map = ft_split(lineal_map, '\n');
	free (lineal_map);
	close(fd);
	return (map);
}

void	init_img(t_mlx_data *d)
{
	d->plyr.player_d = mlx_xpm_file_to_image(d->ptr, \
		ROB_PATHD, &d->width, &d->height);
	d->plyr.player_a = mlx_xpm_file_to_image(d->ptr, \
		ROB_PATHA, &d->width, &d->height);
	d->coin = mlx_xpm_file_to_image(d->ptr, \
		C_PATH, &d->width, &d->height);
	d->floor = mlx_xpm_file_to_image(d->ptr, \
		F_PATH, &d->width, &d->height);
	d->exit = mlx_xpm_file_to_image(d->ptr, \
		D_PATH, &d->width, &d->height);
	d->wall = mlx_xpm_file_to_image(d->ptr, \
		W_PATH, &d->width, &d->height);
	d->counter = mlx_xpm_file_to_image(d->ptr, \
		W_PATH, &d->width, &d->height);
}

void	init_map(t_mlx_data *data)
{
	init_img(data);
	check_extension(data);
	data->map2 = open_map(data);
	data->map1 = open_map(data);
	data->width = ft_strlen(data->map1[0]) * 64;
	data->height = map_height(data->map1) * 64;
	data->plyr.step = 0;
	data->win = mlx_new_window(data->ptr, \
		data->width, data->height, "So_Long");
	if (!data->win)
		free(data->ptr);
	check_map_form(data);
	check_map_comps(data);
	check_perimeter(data);
	check_enough_comp(data);
	ft_check_ways(data);
	draw_map(data);
}
