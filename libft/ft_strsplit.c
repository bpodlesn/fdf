/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:45:20 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/14 15:50:53 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_countwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		ft_slen(const char *s, char c)
{
	int			m;

	m = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		m++;
		s++;
	}
	return (m);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		j;
	int		i;
	int		k;

	if (s == NULL)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * ((ft_countwords(s, c)) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if ((ret[i] = ft_strnew(ft_slen(&s[j], c) + 1)) == NULL)
			ret[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ret[i][k++] = s[j++];
		ret[i][k] = '\0';
	}
	ret[i] = 0;
	return (ret);
}
