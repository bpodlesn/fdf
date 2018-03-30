/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:56:12 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/20 14:17:50 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;

	if (len == 0)
		return ((char*)b);
	a = (unsigned char*)b;
	while (len--)
	{
		*a = (unsigned char)c;
		if (len)
			a++;
	}
	return ((char*)b);
}
