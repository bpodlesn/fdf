/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:04:52 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/09 18:20:27 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	size_t			a;
	unsigned int	b;

	if (s == NULL || f == NULL)
		return (NULL);
	if (!(new = ft_strdup((const char *)s)))
		return (NULL);
	else
	{
		a = 0;
		b = 0;
		while (new[a] != 0)
		{
			new[a] = f(b, new[a]);
			a++;
			b++;
		}
		return (new);
	}
}
