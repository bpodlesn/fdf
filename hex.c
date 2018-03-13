/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:22:15 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/03/06 14:34:12 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_decimal(char *str, int k)
{
	int			s;
	int			r;

	r = 0;
	s = 1;
	r = r * 10 + str[k] - '0';
	return (s * r);
}

int				pows(int i, int j)
{
	int			count;

	count = 1;
	if (j == 1)
		return (1);
	if (j == 2)
		return (i);
	count = 2;
	while (count != j)
	{
		i *= 16;
		count++;
	}
	return (i);
}

t_mlx			tak_nado(t_mlx mlx)
{
	turn_rev_x(mlx, 50, 0);
	turn_y(mlx, 22, 1);
	return (mlx);
}

unsigned int	hextoint(char *temp, int answer, int count, int i)
{
	int			j;
	int			dec;
	int			c;
	char		*hexchar;

	hexchar = "aAbBcCdDeEfF";
	if (temp[0] != '0' || (temp[1] != 'x' && temp[1] != 'X'))
		return (0xffffff);
	while (--i != 1 && count++ > -1 && (c = pows(16, count)))
	{
		if ((temp[i] > 32 && temp[i] < 48) || (temp[i] > 57 && temp[i] < 65)
		|| (temp[i] > 70 && temp[i] < 97) || (temp[i] > 102 && temp[i] <= 127))
			return (0xffffff);
		if (temp[i] >= 48 && temp[i] <= 57)
			dec = ft_decimal(temp, i);
		else
		{
			j = -1;
			while (hexchar[++j] != '\0')
				temp[i] == hexchar[j] ? dec = 10 + (j / 2) : 0;
		}
		answer += c * dec;
	}
	return (answer);
}
