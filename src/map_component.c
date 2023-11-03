/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_component.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-uf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:51:01 by adiaz-uf          #+#    #+#             */
/*   Updated: 2023/10/30 12:52:02 by adiaz-uf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_1(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	is_0(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	is_c(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}

int	is_e(char c)
{
	if (c == 'E')
		return (1);
	return (0);
}

int	is_p(char c)
{
	if (c == 'P')
		return (1);
	return (0);
}
