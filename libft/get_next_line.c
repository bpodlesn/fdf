/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <bpodlesn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:41:07 by bpodlesn          #+#    #+#             */
/*   Updated: 2018/02/02 16:40:16 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					get_next_line(int fd, char **l)
{
	static	char	*s[100];
	char			*temp;
	char			localbuf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !l || BUFF_SIZE < 1 ||
	(ret = read(fd, localbuf, BUFF_SIZE)) == -1)
		return (-1);
	s[fd] = s[fd] ? s[fd] : ft_strdup("");
	temp = s[fd];
	localbuf[ret] = '\0';
	s[fd] = ft_strjoin(s[fd], localbuf);
	free(temp);
	temp = s[fd];
	if (!ft_strlen(s[fd]))
		return (0);
	else if (ft_strchr(s[fd], '\n') &&
		(*l = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd])))
		s[fd] = ft_strdup(ft_strchr(temp, '\n') + 1);
	else if (!ret && ft_strlen(s[fd]) && (*l = ft_strdup(s[fd])))
		s[fd] = NULL;
	else
		return (get_next_line(fd, l));
	free(temp);
	return (1);
}
