/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 09:43:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/24 12:11:36 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	size_t	size_d;

	n = size;
	i = 0;
	if (n != 0)
	{
		while (src[i] != '\0' && --n != 0)
		{
			dest[i] = src[i];
			i++;
		}
		if (src[i] == '\0')
			dest[i] = '\0';
	}
	if (n == 0 && size != 0)
		dest[i] = '\0';
	size_d = ft_strlen(src);
	return (size_d);
}
