/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:28:09 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/02/02 16:38:51 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	one(int key, void *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	if (key == 53)
		exit(0);
	if (key == 124)
		*mlx = ft_hook_right(*mlx);
	if (key == 123)
		*mlx = ft_hook_left(*mlx);
	if (key == 126)
		*mlx = ft_hook_up(*mlx);
	if (key == 125)
		*mlx = ft_hook_down(*mlx);
	if (key == 14)
		*mlx = turn_z(*mlx);
	if (key == 12)
		*mlx = turn_z_rev(*mlx);
}

static void	two(int key, void *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	if (key == 24)
		*mlx = ft_zoom_in(*mlx);
	if (key == 27)
		*mlx = ft_zoom_out(*mlx);
	if (key == 13)
		*mlx = turn_rev_x(*mlx, 5, 1);
	if (key == 0)
		*mlx = turn_y(*mlx, 5, 1);
	if (key == 1)
		*mlx = turn_x(*mlx);
	if (key == 2)
		*mlx = turn_rev_y(*mlx);
	if (key == 15)
		*mlx = reset(*mlx);
}

int			ft_keys(int key, void *zlx)
{
	t_mlx *mlx;

	mlx = (t_mlx*)zlx;
	one(key, mlx);
	two(key, mlx);
	return (0);
}

void		go_home(int c, t_mlx mlx)
{
	if (c == 1)
		ft_putstr("Invalid file");
	if (c == 0)
		ft_putstr("usage: ./fdf file");
	if (c == 2)
		ft_putstr("Invalid hex color");
	free(mlx.buf);
	free(mlx.types);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.size_x = 500.0;
	mlx.nbl = 0;
	mlx.count = 0;
	mlx.i = 0;
	mlx.init = mlx_init();
	mlx.window = mlx_new_window(mlx.init, WIN_X, WIN_Y, "fdf");
	mlx_hook(mlx.window, 2, 5, ft_keys, &mlx);
	if (argc != 2)
		go_home(0, mlx);
	mlx = reader(mlx, open(argv[1], O_RDONLY));
	mlx.x = 500;
	mlx.y = 300;
	mlx.zoom_x = mlx.size_x / mlx.count;
	mlx.zoom_y = mlx.size_x / mlx.nbl;
	mlx = start_draw(0, mlx, 0);
	mlx.center_x = (mlx.types[mlx.count - 1].x
	- mlx.types[0].x) / 2 + mlx.types[0].x;
	mlx.center_y = (mlx.types[mlx.count * mlx.nbl
	- mlx.count].y - mlx.types[0].y) / 2 + mlx.types[0].y;
	tak_nado(mlx);
	mlx_loop(mlx.init);
	return (0);
}
