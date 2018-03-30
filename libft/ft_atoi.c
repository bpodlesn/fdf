/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:50:27 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/13 15:53:12 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					is_neg;
	int					i;
	unsigned long int	number;

	i = 0;
	is_neg = 1;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		number = number * 10 + ((int)str[i] - '0');
		if (is_neg == -1 && number > 9223372036854775807)
			return (0);
		else if (is_neg == 1 && number > 9223372036854775806)
			return (-1);
		i++;
	}
	return (number * is_neg);
}
