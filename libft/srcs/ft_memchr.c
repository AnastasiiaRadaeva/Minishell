/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:46:51 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/15 09:19:52 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		sym;

	p = (const unsigned char *)s;
	sym = (unsigned char)c;
	while (n > 0)
	{
		if (*p == sym)
			return ((void *)p);
		n--;
		p++;
	}
	return (NULL);
}
