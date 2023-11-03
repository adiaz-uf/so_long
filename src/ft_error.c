/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:12 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:36:14 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_close(t_mlx_data *win, int err)
{
	ft_free(win->map1);
	ft_free(win->map2);
	mlx_clear_window(win->ptr, win->win);
	mlx_destroy_window(win->ptr, win->win);
	free(win->ptr);
	ft_putendl_fd(CYAN"\nGAME ENDED\n"END, 1);
	exit(err);
}

void	ft_error(char *msg, int err, t_mlx_data *d)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_close(d, err);
}

void	ft_exit(char *msg, int err, t_mlx_data *d)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(err);
}
