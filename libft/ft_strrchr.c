/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:43:30 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/10/30 16:49:11 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	char *a;

	a = (char *)string + ft_strlen(string);
	while (*a != c)
	{
		if (a == string)
		{
			return (NULL);
		}
		a--;
	}
	return (a);
}
