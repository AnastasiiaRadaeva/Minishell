/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:28:21 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/19 19:03:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void			*p;
	size_t			len;

	p = ft_memchr(src, c, n);
	len = p - src + 1;
	if (p != NULL)
		return (ft_memcpy(dest, src, len) + len);
	ft_memcpy(dest, src, n);
	return (NULL);
}
