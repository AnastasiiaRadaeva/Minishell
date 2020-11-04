/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 09:53:48 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/24 11:18:56 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char*)s;
	while (*p != '\0')
	{
		if (*p == c)
			return (p);
		else if (*p == '\0')
			return (NULL);
		p++;
	}
	if (c == '\0')
		return (p);
	return (0);
}
