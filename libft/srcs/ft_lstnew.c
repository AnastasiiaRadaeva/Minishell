/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:36:00 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/21 12:25:26 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(char *content)
{
	t_list	*lstnew;

	if (!(lstnew = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
