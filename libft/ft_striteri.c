/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:53:20 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/11 17:04:28 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int a;

	if (s == NULL || f == NULL)
		return ;
	else
	{
		a = 0;
		{
			while (*s != '\0')
			{
				f(a, s);
				a++;
				s++;
			}
		}
	}
}
