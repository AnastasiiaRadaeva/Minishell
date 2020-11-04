/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 11:13:47 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/23 18:01:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*nlst;
	void	*cnt_mod;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		cnt_mod = f(lst->content);
		if (!(p = ft_lstnew(cnt_mod)))
		{
			free(cnt_mod);
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, p);
		lst = lst->next;
	}
	return (nlst);
}
