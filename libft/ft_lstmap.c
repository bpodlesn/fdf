/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpodlesn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:04:12 by bpodlesn          #+#    #+#             */
/*   Updated: 2017/11/14 16:28:57 by bpodlesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *this;
	t_list *start;

	if (!lst || !f)
		return (NULL);
	this = f(lst);
	if ((new = ft_lstnew(this->content, this->content_size)) == NULL)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		this = f(lst);
		if ((new->next = ft_lstnew(this->content, this->content_size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
