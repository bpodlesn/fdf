/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:26:41 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/08 16:05:19 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t den;

	den = 0;
	while (src[den] != '\0' && den < len)
	{
		dst[den] = src[den];
		den++;
	}
	while (den < len)
	{
		dst[den] = '\0';
		den++;
	}
	return (dst);
}
