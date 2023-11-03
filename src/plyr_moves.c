/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plyr_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:46:56 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/31 11:49:35 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_movement_x(t_mlx_data *d, int m)
{
	int		i;
	int		j;
	char	pos;

	i = (d->plyr.spr.x0 + m) / 64;
	j = d->plyr.spr.y0 / 64;
	pos = d->map1[i][j];
	if (pos == '1')
		return (FALSE);
	else if (pos == 'C')
		d->map1[i][j] = '0';
	else if (pos == 'E' && d->n_collectables != 0)
		return (FALSE);
	else if (pos == 'E' && d->n_collectables == 0)
		ft_close(d, 20);
	return (TRUE);
}

int	check_movement_y(t_mlx_data *d, int m)
{
	int		i;
	int		j;
	char	pos;

	i = d->plyr.spr.x0 / 64;
	j = (d->plyr.spr.y0 + m) / 64;
	pos = d->map1[i][j];
	if (pos == '1')
		return (FALSE);
	else if (pos == 'C')
		d->map1[i][j] = '0';
	else if (pos == 'E' && d->n_collectables != 0)
		return (FALSE);
	else if (pos == 'E' && d->n_collectables == 0)
		ft_close(d, 20);
	return (TRUE);
}

void	ft_move_x(t_mlx_data *data, int movement)
{
	if (check_movement_x(data, movement))
	{
		draw_floor(data);
		draw_walls(data);
		draw_collectables(data);
		data->plyr.spr.x0 += movement;
		data->plyr.spr.x = data->plyr.spr.x0;
		data->plyr.spr.y = data->plyr.spr.y0;
		if (data->plyr.dir == 1)
		{
			mlx_put_image_to_window(data->ptr, data->win, \
				data->plyr.player_d, data->plyr.spr.y, data->plyr.spr.x);
		}
		else
		{
			mlx_put_image_to_window(data->ptr, data->win, \
				data->plyr.player_a, data->plyr.spr.y, data->plyr.spr.x);
		}
		data->plyr.step++;
		ft_print_steps(data);
	}
}

void	ft_move_y(t_mlx_data *data, int movement)
{
	if (check_movement_y(data, movement))
	{
		draw_floor(data);
		draw_walls(data);
		draw_collectables(data);
		data->plyr.spr.y0 += movement;
		data->plyr.spr.x = data->plyr.spr.x0;
		data->plyr.spr.y = data->plyr.spr.y0;
		if (movement > 0)
		{
			mlx_put_image_to_window(data->ptr, data->win, \
				data->plyr.player_d, data->plyr.spr.y0, data->plyr.spr.x0);
			data->plyr.dir = 1;
		}
		else
		{
			mlx_put_image_to_window(data->ptr, data->win, \
				data->plyr.player_a, data->plyr.spr.y0, data->plyr.spr.x0);
			data->plyr.dir = 0;
		}
		data->plyr.step++;
		ft_print_steps(data);
	}
}
