/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:19:43 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/09 14:49:31 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*n;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	if (!(n = (char *)malloc(sizeof(*n) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		n[i] = s1[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
