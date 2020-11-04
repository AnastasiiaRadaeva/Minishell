/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:05:06 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/20 15:38:32 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	const	char	*s;
	char			*d;

	s = src;
	d = dest;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
