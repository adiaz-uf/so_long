/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:39:03 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:39:05 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int key, t_mlx_data *data)
{
	if (key == ESC)
		ft_close(data, 17);
	else if (key == KEY_DOWN || key == KEY_S)
	{
		ft_move_x(data, 64);
	}
	else if (key == KEY_UP || key == KEY_W)
	{
		ft_move_x(data, -64);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		ft_move_y(data, -64);
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		ft_move_y(data, 64);
	}
	return (0);
}
