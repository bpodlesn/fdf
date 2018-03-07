/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:38:52 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/06 15:00:23 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			how_many(char *line)
{
	int		i;
	int		counter;
	int		j;

	j = 0;
	i = 0;
	counter = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			j = 0;
			while (line[i] == ' ')
				i++;
		}
		if (j == 0)
		{
			counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

char		*newbuf(char *line, int a, int i, int j)
{
	char	*newline;
	char	*asd;

	asd = ft_strnew(a);
	newline = asd;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			while (line[i] != ' ')
			{
				if (line[i] == '\0')
					return (newline);
				i++;
			}
		newline[j] = line[i];
		i++;
		j++;
	}
	if (j == a)
		return (line);
	free(asd);
	return (newline);
}

t_mlx		colorline(char *line, t_mlx mlx, unsigned int i, unsigned int j)
{
	char	*newline;

	newline = ft_strnew(100);
	while (line[++i] != '\0')
	{
		if (line[i] == ',' && ++i)
		{
			while (line[i + 1] != ' ' && line[i + 1]
			!= '\0' && line[i + 1] != '\n')
				newline[j++] = line[i++];
			newline[j] = line[i];
			mlx.types[mlx.i].color =
			hextoint(newline, 0, 0, ft_strlen(newline) - 1);
			mlx.i++;
			ft_strclr(newline);
			j = 0;
			i++;
			if (line[i] == '\n')
				i++;
		}
		if ((line[i] != ' ' && (line[i + 1] == ' ' ||
		line[i + 1] == '\n' || line[i + 1] == '\0')))
			mlx.types[mlx.i++].color = 16777215;
	}
	return (mlx);
}

t_mlx		z(char *buf, t_mlx mlx)
{
	int		i;

	i = 0;
	mlx.i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != ' ')
		{
			mlx.types[mlx.i].z = (ft_atoi1(buf, &i)) * 5;
			mlx.i++;
		}
		i++;
	}
	return (mlx);
}

t_mlx		reader(t_mlx mlx, int fd)
{
	char	*line;
	char	*buf;
	char	*new;

	buf = ft_strnew(1);
	new = buf;
	while (get_next_line(fd, &line) > 0 && mlx.nbl++ > -1)
	{
		new = ft_strjoin(ft_strjoin(new, line), "\n");
		line = newbuf(line, ft_strlen(line), 0, 0);
		if (mlx.count == 0)
			mlx.count = how_many(line);
		else if (mlx.count != how_many(line))
			go_home(1);
		buf = ft_strjoin(ft_strjoin(buf, line), "\n");
	}
	if (get_next_line(fd, &line) <= -1)
		go_home(0);
	mlx.types = malloc(sizeof(t_types) * (mlx.nbl * mlx.count) - 1);
	mlx = colorline(new, mlx, -1, 0);
	mlx = z(buf, mlx);
	return (mlx);
}
