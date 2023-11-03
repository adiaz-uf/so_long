/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:59:00 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:59:02 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_print_steps(t_mlx_data *data)
{
	char	*steps;

	steps = ft_itoa(data->plyr.step);
	ft_putstr_fd(BHYEL"Steps -> "END, 1);
	ft_putendl_fd(steps, 1);
	mlx_put_image_to_window(data->ptr, data->win, data->counter, 0, 0);
	mlx_string_put(data->ptr, data->win, 22, 22, 0x00FFFFFF, steps);
	free(steps);
}
