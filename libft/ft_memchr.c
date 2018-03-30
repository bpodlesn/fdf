/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:46:52 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/06 14:31:14 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *a;
	unsigned char c2;

	a = (unsigned char *)s;
	c2 = c;
	while (n--)
	{
		if (*a == c2)
			return (a);
		else
			a++;
	}
	return (0);
}
