/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:53:02 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/09 18:32:21 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		a;
	char	*sub;
	size_t	w;

	if (s == NULL)
		return (NULL);
	a = ft_strlen(s);
	if (!(sub = malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	if (a >= (int)len)
	{
		w = 0;
		while (w < len)
		{
			sub[w] = s[start + w];
			w++;
		}
		sub[w] = '\0';
		return (sub);
	}
	else
		return (NULL);
}
