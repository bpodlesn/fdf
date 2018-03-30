/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:16:30 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/14 17:24:45 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*a;
	char	*b;
	size_t	testlen;

	if (!*little)
		return ((void *)big);
	while (*big && len-- != 0)
	{
		if (*big == *little)
		{
			testlen = len;
			a = (void *)big + 1;
			b = (void *)little + 1;
			while (*a && *b && *a == *b && testlen--)
			{
				a++;
				b++;
			}
			if (!*b)
				return ((void*)big);
		}
		big++;
	}
	return (NULL);
}
