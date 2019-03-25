/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_lsth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:10:55 by amartino          #+#    #+#             */
/*   Updated: 2018/12/18 15:24:40 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_find_lsth(t_list *lst, size_t umpteenth)
{
	t_list		*tmp;
	size_t		i;

	tmp = lst->next;
	if (umpteenth == 0)
	{
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	i = 0;
	while (i <= umpteenth)
	{
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
