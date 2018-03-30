/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:01:35 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/20 14:36:58 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t a;
	size_t d;
	size_t s;
	size_t i;

	d = ft_strlen(s1);
	s = ft_strlen(s2);
	if (d < size)
	{
		a = d;
		i = 0;
		while (a < (size - 1))
			s1[a++] = s2[i++];
		s1[a] = '\0';
		return (d + s);
	}
	else
		return (s + size);
}
