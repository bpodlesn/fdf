/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:59:38 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/06 14:45:45 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIN_X 1500
# define WIN_Y 1100

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_types
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_types;

typedef struct		s_mlx
{
	double			size_x;
	double			size_y;
	void			*init;
	void			*window;
	char			*buf;
	double			x;
	double			xx;
	double			yy;
	double			y;
	double			z;
	int				count;
	int				nbl;
	double			zoom_x;
	double			zoom_y;
	int				num;
	int				k;
	int				i;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	double			center_x;
	double			center_y;
	t_types			*types;
}					t_mlx;

int					ft_keys(int key, void *zlx);
int					ft_decimal(char *str, int k);
int					how_many(char *line, int counter);
unsigned int		hextoint(char *temp, int answer, int count, int i);
void				draw_lines(t_mlx mlx);
void				instruction(t_mlx mlx);
void				go_home(int c, t_mlx mlx);
void				draw_coord(t_mlx mlx, int c);
void				newseg(t_mlx mlx, int c);
t_mlx				ft_hook_right(t_mlx mlx);
t_mlx				start_draw(int j, t_mlx mlx, int k);
t_mlx				ft_hook_left(t_mlx mlx);
t_mlx				ft_hook_down(t_mlx mlx);
t_mlx				ft_hook_up(t_mlx mlx);
t_mlx				ft_zoom_in(t_mlx mlx);
t_mlx				ft_zoom_out(t_mlx mlx);
t_mlx				reader(t_mlx mlx, int fd);
t_mlx				colorline(t_mlx mlx,
					unsigned int i, unsigned int j);
t_mlx				find_center(t_mlx mlx);
t_mlx				back_center(t_mlx mlx);
t_mlx				turn_rev_y(t_mlx mlx);
t_mlx				turn_rev_x(t_mlx mlx, int c, int k);
t_mlx				turn_y(t_mlx mlx, int c, int k);
t_mlx				turn_x(t_mlx mlx);
t_mlx				tak_nado(t_mlx mlx);
t_mlx				turn_z(t_mlx mlx);
t_mlx				turn_z_rev(t_mlx mlx);
t_mlx				reset(t_mlx mlx);
t_mlx				z(t_mlx mlx);

#endif
