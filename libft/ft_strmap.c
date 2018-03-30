/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:52:00 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:54 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char	const *s, char (*f)(char))
{
	char	*new;
	size_t	a;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = ft_strdup((const char *)s)))
		return (NULL);
	else
	{
		a = 0;
		while (new[a] != '\0')
		{
			new[a] = f(new[a]);
			a++;
		}
		return (new);
	}
}
