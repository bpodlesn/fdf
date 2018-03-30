/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:32:36 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/20 14:14:56 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	a;
	char	*b;

	if (size == 0)
		return (NULL);
	b = malloc(size);
	if (b == NULL)
		return (NULL);
	a = 0;
	while (a < size)
	{
		b[a] = 0;
		a++;
	}
	return (b);
}
