/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:57:42 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/11/03 11:44:10 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	game;

	if (argc != 2)
		ft_exit(RED"Numero de argumentos incorrecto"END, 5, &game);
	game.ptr = mlx_init();
	if (!game.ptr)
		return (1);
	game.map = argv[1];
	init_map(&game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_hook(game.win, 2, 0, handle_input, &game);
	mlx_loop(game.ptr);
	return (0);
}
