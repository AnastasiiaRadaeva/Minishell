/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:28:53 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/12 12:06:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnrchr(const char *s, int c, size_t size)
{
	char			*res;
	size_t			i;

	i = ft_strlen(s);
	res = NULL;
	while (i && size)
	{
		if (s[i] == (char)c)
			res = (char *)&s[i];
		i--;
		size--;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (res);
}
