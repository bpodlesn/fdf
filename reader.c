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

int			how_many(char *line, int counter)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
			{
				if (line[i + 1] != ' ' && line[i + 1] != '\0')
					j = 0;
				i++;
			}
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

char		*ft_strjo(char *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * (len1 + len2 + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}

char		*newbuf(char *line, int a, int i, int j)
{
	char	*newline;

	newline = ft_strnew(a);
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
	{
		free(newline);
		return (line);
	}
	return (newline);
}

t_mlx		colorline(t_mlx mlx, unsigned int i, unsigned int j)
{
	char	*newline;

	newline = ft_strnew(100);
	while (mlx.buf[++i] != '\0')
	{
		if (mlx.buf[i] == ',' && ++i)
		{
			while (mlx.buf[i + 1] != ' ' && mlx.buf[i + 1]
			!= '\0' && mlx.buf[i + 1] != '\n')
				newline[j++] = mlx.buf[i++];
			newline[j] = mlx.buf[i];
			mlx.types[mlx.i].color =
			hextoint(newline, 0, 0, ft_strlen(newline));
			mlx.i++;
			ft_strclr(newline);
			j = 0;
			i++;
			mlx.buf[i] == '\n' ? i++ : 0;
		}
		if ((mlx.buf[i] != ' ' && (mlx.buf[i + 1] == ' ' ||
		mlx.buf[i + 1] == '\n' || mlx.buf[i + 1] == '\0')))
			mlx.types[mlx.i++].color = 16777215;
	}
	free(newline);
	return (mlx);
}

t_mlx		reader(t_mlx mlx, int fd)
{
	char	*line;
	char	*asd;

	mlx.buf = ft_strnew(100);
	while (get_next_line(fd, &line) > 0 && mlx.nbl++ > -1)
	{
		asd = line;
		if (mlx.count == 0)
			mlx.count = how_many(line, 0);
		else if (mlx.count != how_many(line, 0))
			go_home(1, mlx);
		mlx.buf = ft_strjo(ft_strjo(mlx.buf, line), "\n");
		free(asd);
	}
	mlx.nbl == 0 ? go_home(1, mlx) : 0;
	get_next_line(fd, &line) <= -1 ? go_home(0, mlx) : 0;
	mlx.types = malloc(sizeof(t_types) * ((mlx.nbl * mlx.count) + 1));
	mlx = colorline(mlx, -1, 0);
	mlx = z(mlx);
	close(fd);
	return (mlx);
}
