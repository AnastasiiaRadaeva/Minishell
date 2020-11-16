/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 20:14:09 by amalliar          #+#    #+#             */
/*   Updated: 2020/11/12 15:31:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (res);
}
