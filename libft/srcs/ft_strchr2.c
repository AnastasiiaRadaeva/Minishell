/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:53:34 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/13 15:57:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr2(const char *s1, const char *s2)
{
	char	*p_s1;

	p_s1 = (char *)s1;
	size_t	i;
	size_t	i_s2;
	
	i_s2 = ft_strlen(s2);
	while (*p_s1)
	{
		i = -1;
		while (++i < i_s2)
		{
			if (p_s1[0] == s2[i])
				return (p_s1);
		}
		p_s1++;
	}
	return (NULL);
}
