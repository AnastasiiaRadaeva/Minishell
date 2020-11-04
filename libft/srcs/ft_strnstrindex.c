/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:18:59 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/12 09:23:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnstrindex(char *big, char *little)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (big == NULL)
		return (0);
	while (big[++i])
	{
		if (big[i] == little[0])
		{
			j = 1;
			while (little[j] && big[i + j] == little[j])
				j++;
			if (little[j] == '\0')
				return (i + j - 1);
		}
	}
	return (0);
}
