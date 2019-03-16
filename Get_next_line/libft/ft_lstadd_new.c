/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 18:29:52 by amartino          #+#    #+#             */
/*   Updated: 2019/03/16 22:23:08 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstadd_new(t_list *lst, size_t size)
{
	t_list	*tmp;
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	tmp = lst->next;
	if (!(new_lst = ft_memalloc(sizeof(size))))
		return (NULL);
	lst->next = new_lst;
	lst->next->next = tmp;
	return (lst);
}
