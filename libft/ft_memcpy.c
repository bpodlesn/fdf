/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:02:09 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/10/30 20:03:37 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *src, size_t n)
{
	char *d;
	char *s;

	d = (char *)destination;
	s = (char *)src;
	if (n == 0 || destination == src)
		return (destination);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (destination);
}
