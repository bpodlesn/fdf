/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:40:45 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/06 14:27:51 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		turn_rev_x(t_mlx mlx)
{
	int		i;
	double	y;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		y = mlx.types[i].y;
		mlx.types[i].y = mlx.types[i].y * cos(5 * (3.14 / 180))
		- mlx.types[i].z * sin(5 * (3.14 / 180));
		mlx.types[i].z = y * sin(5 * (3.14 / 180))
		+ mlx.types[i].z * cos(5 * (3.14 / 180));
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		turn_x(t_mlx mlx)
{
	int		i;
	double	y;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		y = mlx.types[i].y;
		mlx.types[i].y = mlx.types[i].y * cos(5 * (3.14 / 180))
		+ mlx.types[i].z * sin(5 * (3.14 / 180));
		mlx.types[i].z = -y * sin(5 * (3.14 / 180))
		+ mlx.types[i].z * cos(5 * (3.14 / 180));
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		turn_rev_y(t_mlx mlx)
{
	int		i;
	double	x;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		x = mlx.types[i].x;
		mlx.types[i].x = mlx.types[i].x * cos(5 * (3.14 / 180))
		- mlx.types[i].z * sin(5 * (3.14 / 180));
		mlx.types[i].z = x * sin(5 * (3.14 / 180))
		+ mlx.types[i].z * cos(5 * (3.14 / 180));
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		turn_y(t_mlx mlx)
{
	int		i;
	double	x;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		x = mlx.types[i].x;
		mlx.types[i].x = mlx.types[i].x * cos(5 * (3.14 / 180))
		+ mlx.types[i].z * sin(5 * (3.14 / 180));
		mlx.types[i].z = -x * sin(5 * (3.14 / 180))
		+ mlx.types[i].z * cos(5 * (3.14 / 180));
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		ft_zoom_out(t_mlx mlx)
{
	int		i;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].y *= 0.9;
		mlx.types[i].x *= 0.9;
		mlx.types[i].z *= 0.9;
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}
