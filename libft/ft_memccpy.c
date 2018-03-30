/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:10:09 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/06 17:05:13 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	f;

	f = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (f < n)
	{
		c1[f] = c2[f];
		if (c2[f] == (char)c)
			return (c1 + f + 1);
		f++;
	}
	return (NULL);
}
