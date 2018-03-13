/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:49:22 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/13 14:49:33 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		turn_z(t_mlx mlx)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		x = mlx.types[i].x;
		y = mlx.types[i].y;
		mlx.types[i].x = mlx.types[i].x * cos(5 * (3.14 / 180))
		- mlx.types[i].y * sin(5 * (3.14 / 180));
		mlx.types[i].y = x * sin(5 * (3.14 / 180))
		+ y * cos(5 * (3.14 / 180));
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		turn_z_rev(t_mlx mlx)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		x = mlx.types[i].x;
		y = mlx.types[i].y;
		mlx.types[i].x = mlx.types[i].x * cos(5 * (3.14 / 180))
		+ mlx.types[i].y * sin(5 * (3.14 / 180));
		mlx.types[i].y = -x * sin(5 * (3.14 / 180))
		+ y * cos(5 * (3.14 / 180));
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		ft_zoom_in(t_mlx mlx)
{
	int i;

	i = 0;
	mlx_clear_window(mlx.init, mlx.window);
	mlx = find_center(mlx);
	while (i < mlx.count * mlx.nbl)
	{
		mlx.types[i].y *= 1.1;
		mlx.types[i].x *= 1.1;
		mlx.types[i].z *= 1.1;
		i++;
	}
	mlx = back_center(mlx);
	draw_coord(mlx, 1);
	instruction(mlx);
	return (mlx);
}

t_mlx		z(t_mlx mlx)
{
	int		i;

	i = 0;
	mlx.i = 0;
	while (mlx.buf[i] != '\0')
	{
		if (mlx.buf[i] != ' ' || mlx.buf[i] != '\n')
		{
			mlx.types[mlx.i].z = (ft_atoi1(mlx.buf, &i)) * 2;
			if (mlx.buf[i] != ' ' && mlx.buf[i] != ',' && mlx.buf[i] != '\n')
				mlx.types[mlx.i].z = 0;
			mlx.i++;
			while (mlx.buf[i] != ' ' && mlx.buf[i] != '\n')
				i++;
		}
		if (mlx.buf[i] == ' ' || mlx.buf[i] == '\n')
			while (mlx.buf[i] == ' ' || mlx.buf[i] == '\n')
				i++;
		else
			while (mlx.buf[i] == ' ' || mlx.buf[i] == '\n')
				i++;
	}
	return (mlx);
}
