/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:11:30 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/23 07:44:37 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*plst;

	if (lst && new)
	{
		if (!(*lst))
			*lst = new;
		else
		{
			plst = ft_lstlast(*lst);
			plst->next = new;
		}
	}
}
