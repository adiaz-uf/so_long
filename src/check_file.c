/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:29:52 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 11:29:54 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_extension(t_mlx_data *d)
{
	char	*dot;

	dot = ft_strchr(d->map, '.');
	dot++;
	if (ft_strncmp(dot, "ber", 4) == 0)
		return ;
	else
		ft_exit(RED"Error\nInvalid file extension"END, 10, d);
}
