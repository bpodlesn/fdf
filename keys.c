/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:45:19 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/16 14:09:11 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	ft_hook_right(t_mlx mlx)
{
	int i;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].x += 10;
		i++;
	}
	mlx.center_x += 10;
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx	ft_hook_left(t_mlx mlx)
{
	int i;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].x -= 10;
		i++;
	}
	mlx.center_x -= 10;
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx	ft_hook_up(t_mlx mlx)
{
	int i;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].y -= 10;
		i++;
	}
	mlx.center_y -= 10;
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx	ft_hook_down(t_mlx mlx)
{
	int i;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].y += 10;
		i++;
	}
	mlx.center_y += 10;
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}
