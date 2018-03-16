/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 13:06:53 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/16 14:28:13 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dx_dy(t_mlx mlx, int i)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;

	d = (mlx.dy << 1) - mlx.dx;
	d1 = mlx.dy << 1;
	d2 = (mlx.dy - mlx.dx) << 1;
	x = mlx.types[mlx.i].x + mlx.sx;
	y = mlx.types[mlx.i].y;
	mlx_pixel_put(mlx.init, mlx.window, mlx.types[mlx.i].x,
	mlx.types[mlx.i].y, mlx.types[mlx.i].color);
	while (i++ <= mlx.dx)
	{
		if (d > 0)
		{
			d += d2;
			y += mlx.sy;
		}
		else
			d += d1;
		mlx_pixel_put(mlx.init, mlx.window, x, y, mlx.types[mlx.i].color);
		x += mlx.sx;
	}
}

void	dy_dx(t_mlx mlx, int i)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;

	d = (mlx.dx << 1) - mlx.dy;
	d1 = mlx.dx << 1;
	d2 = (mlx.dx - mlx.dy) << 1;
	x = mlx.types[mlx.i].x;
	y = mlx.types[mlx.i].y + mlx.sy;
	mlx_pixel_put(mlx.init, mlx.window,
	mlx.types[mlx.i].x, mlx.types[mlx.i].y, mlx.types[mlx.i].color);
	while (i++ <= mlx.dy)
	{
		if (d > 0)
		{
			d += d2;
			x += mlx.sx;
		}
		else
			d += d1;
		mlx_pixel_put(mlx.init, mlx.window, x, y, mlx.types[mlx.i].color);
		y += mlx.sy;
	}
}

void	newseg(t_mlx mlx, int c)
{
	if (c == 1)
	{
		mlx.dx = fabs(mlx.types[mlx.i + mlx.count].x - mlx.types[mlx.i].x);
		mlx.dy = fabs(mlx.types[mlx.i + mlx.count].y - mlx.types[mlx.i].y);
		mlx.sx = mlx.types[mlx.i + mlx.count].x >= mlx.types[mlx.i].x ? 1 : -1;
		mlx.sy = mlx.types[mlx.i + mlx.count].y >= mlx.types[mlx.i].y ? 1 : -1;
	}
	else
	{
		mlx.dx = fabs(mlx.types[mlx.i + 1].x - mlx.types[mlx.i].x);
		mlx.dy = fabs(mlx.types[mlx.i + 1].y - mlx.types[mlx.i].y);
		mlx.sx = mlx.types[mlx.i + 1].x >= mlx.types[mlx.i].x ? 1 : -1;
		mlx.sy = mlx.types[mlx.i + 1].y >= mlx.types[mlx.i].y ? 1 : -1;
	}
	if (mlx.dy <= mlx.dx)
		dx_dy(mlx, 1);
	else
		dy_dx(mlx, 1);
}

t_mlx	find_center(t_mlx mlx)
{
	int i;

	i = 0;
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].x -= mlx.center_x;
		mlx.types[i].y -= mlx.center_y;
		i++;
	}
	return (mlx);
}

t_mlx	back_center(t_mlx mlx)
{
	int i;

	i = 0;
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].x += mlx.center_x;
		mlx.types[i].y += mlx.center_y;
		i++;
	}
	return (mlx);
}
