/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:36:11 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/06 13:28:02 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_coord(t_mlx mlx, int c)
{
	if (c == 1)
		draw_lines(mlx);
	else
		mlx_clear_window(mlx.init, mlx.window);
}

void	draw_lines(t_mlx mlx)
{
	int cnt;

	mlx.i = 0;
	cnt = mlx.count;
	while (mlx.i < (mlx.count * mlx.nbl))
	{
		while (mlx.i < cnt)
		{
			if (mlx.i + mlx.count > mlx.count * mlx.nbl - 1)
			{
				if (mlx.i + 1 != cnt)
					newseg(mlx, 0);
			}
			else if (mlx.i == cnt - 1)
				newseg(mlx, 1);
			else
			{
				newseg(mlx, 1);
				newseg(mlx, 0);
			}
			mlx.i++;
		}
		cnt += mlx.count;
	}
}

t_mlx	start_draw(int i, int j, t_mlx mlx, int k)
{
	double xx;
	double yy;

	xx = mlx.x;
	yy = mlx.y;
	mlx.num = 0;
	while (mlx.num < mlx.nbl)
	{
		while (j++ != mlx.count)
		{
			if (i == 1)
				mlx_pixel_put(mlx.init, mlx.window, xx, yy, mlx.types[k].color);
			else
				mlx_pixel_put(mlx.init, mlx.window, xx, yy, 0);
			mlx.types[k].x = xx;
			mlx.types[k].y = yy;
			k++;
			xx += mlx.zoom_x;
		}
		j = 0;
		yy += mlx.zoom_y;
		xx = mlx.x;
		mlx.num++;
	}
	return (mlx);
}

void	instruction(t_mlx mlx)
{
	mlx_string_put(mlx.init, mlx.window, 5, 20, 0xffffff,
	"left/right/up/down to move");
	mlx_string_put(mlx.init, mlx.window, 5, 50, 0xffffff, "+/- to zoom in/out");
	mlx_string_put(mlx.init, mlx.window, 5, 80, 0xffffff, "rotation W/A/S/D");
}
