/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:47:25 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/13 15:56:10 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char		*ft_itoa(int n)
{
	int		sign;
	char	*s;
	int		l;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = 2;
	sign = 0;
	i = n;
	ft_neg(&n, &sign);
	while (i /= 10)
		l++;
	l += sign;
	if (!(s = (char *)malloc(sizeof(*s) * l)))
		return (NULL);
	s[--l] = '\0';
	while (l--)
	{
		s[l] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		s[0] = '-';
	return (s);
}
