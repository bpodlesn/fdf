/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:18:13 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/10/30 14:40:45 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	char *a;

	a = (char *)string;
	while (*a != symbol)
	{
		if (*a == '\0')
		{
			return (NULL);
		}
		a++;
	}
	return (a);
}
