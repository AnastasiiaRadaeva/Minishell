/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 10:36:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/20 12:00:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*dell;
	t_list	*plst;

	if (lst && del)
	{
		plst = *lst;
		while (plst)
		{
			dell = plst;
			plst = plst->next;
			ft_lstdelone(dell, del);
		}
		*lst = NULL;
	}
}
