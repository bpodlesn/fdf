/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:21:52 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/10/30 18:00:46 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*a;
	char	*b;

	if (!*little)
		return ((void *)big);
	while (*big)
	{
		if (*big == *little)
		{
			a = (void *)big + 1;
			b = (void *)little + 1;
			while (*a && *b && *a == *b)
			{
				++a;
				++b;
			}
			if (!*b)
				return ((void *)big);
		}
		big++;
	}
	return (NULL);
}
