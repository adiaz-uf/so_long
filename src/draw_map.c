/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:13 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:24:43 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_walls(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map1[i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (is_1(d->map1[i][j]))
			{
				mlx_put_image_to_window(d->ptr, d->win, \
					d->wall, 64 * j, i * 64);
			}
			if (is_e(d->map1[i][j]))
			{
				mlx_put_image_to_window(d->ptr, d->win, \
					d->exit, 64 * j, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_floor(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map1[i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (!is_1(d->map1[i][j]))
			{
				mlx_put_image_to_window(d->ptr, d->win, \
					d->floor, 64 * j, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_collectables(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	d->n_collectables = 0;
	while (d->map1[i])
	{
		j = 0;
		while (d->map1[i][j])
		{
			if (is_c(d->map1[i][j]))
			{
				d->n_collectables++;
				mlx_put_image_to_window(d->ptr, d->win, \
					d->coin, 64 * j, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_plyr(t_mlx_data *d)
{
	int	i;
	int	j;

	i = 0;
	find_player(d);
	d->plyr.dir = 1;
	mlx_put_image_to_window(d->ptr, d->win, \
		d->plyr.player_d, d->plyr.spr.y0, d->plyr.spr.x0);
}

int	draw_map(t_mlx_data *d)
{
	draw_floor(d);
	draw_walls(d);
	draw_collectables(d);
	draw_plyr(d);
	return (0);
}
