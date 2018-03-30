/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:48:33 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/11 17:42:41 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ws(const char *s)
{
	int		i;
	int		j;

	j = ft_strlen((char *)s) - 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		if (s[i] == '\0')
			return (0);
	}
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (j < i)
		i = 0;
	j = j - i + 1;
	return (j);
}

char		*ft_strtrim(char const *s)
{
	int		l;
	char	*m;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	l = ft_ws(s);
	i = 0;
	j = 0;
	if (!(m = (char *)malloc(sizeof(*m) * (l + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0' && j < l)
	{
		m[j] = s[i];
		i++;
		j++;
	}
	m[j] = '\0';
	return (m);
}
