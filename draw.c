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

void		draw_coord(t_mlx mlx, int c)
{
	if (c == 1)
		draw_lines(mlx);
	else
		mlx_clear_window(mlx.init, mlx.window);
}

void		draw_lines(t_mlx mlx)
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

t_mlx		start_draw(int j, t_mlx mlx, int k)
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

t_mlx		reset(t_mlx mlx)
{
	mlx_clear_window(mlx.init, mlx.window);
	mlx = z(mlx);
	mlx = start_draw(0, mlx, 0);
	mlx.center_x = (mlx.types[mlx.count - 1].x
	- mlx.types[0].x) / 2 + mlx.types[0].x;
	mlx.center_y = (mlx.types[mlx.count * mlx.nbl
	- mlx.count].y - mlx.types[0].y) / 2 + mlx.types[0].y;
	draw_coord(mlx, 1);
	tak_nado(mlx);
	return (mlx);
}

void		instruction(t_mlx mlx)
{
	mlx_string_put(mlx.init, mlx.window, 5, 20, 0x51f6ff,
	"LEFT/RIGHT/UP/DOWN");
	mlx_string_put(mlx.init, mlx.window, 190, 20, 0xffffff,
	"to move");
	mlx_string_put(mlx.init, mlx.window, 5, 50, 0x51f6ff, "+/-");
	mlx_string_put(mlx.init, mlx.window, 40, 50, 0xffffff,
	"to ZOOM in/out");
	mlx_string_put(mlx.init, mlx.window, 5, 80, 0xffffff, "ROTATION -");
	mlx_string_put(mlx.init, mlx.window, 115, 80, 0x51f6ff, "W/A/S/D");
	mlx_string_put(mlx.init, mlx.window, 5, 110, 0xffffff, "ROTATION -");
	mlx_string_put(mlx.init, mlx.window, 115, 110, 0x51f6ff, "Q/E");
	mlx_string_put(mlx.init, mlx.window, 5, 140, 0xffffff, "RESET -");
	mlx_string_put(mlx.init, mlx.window, 85, 140, 0x51f6ff, "R");
	mlx_string_put(mlx.init, mlx.window, 5, 170, 0xe5194f, "EXIT - ESC");
}
