/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:44:53 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/03 16:33:06 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	a = 0;
	while (a < n)
	{
		if (s1[a] == '\0' || s2[a] == '\0')
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		else if (s1[a] == s2[a])
			a++;
		else if (s1[a] != s2[a])
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
	}
	return (0);
}
