/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:06:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 14:02:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr2(const char *s1, const char *s2)
{
	char	*p_s1;
	size_t	i;
	size_t	i_s1;
	size_t	i_s2;

	p_s1 = (char *)s1;
	i_s1 = ft_strlen(s1);
	i_s2 = ft_strlen(s2);
	while (i_s1)
	{
		i = -1;
		while (++i < i_s2)
		{
			if (p_s1[i_s1] == s2[i])
				return ((char *)&p_s1[i_s1]);
		}
		i_s1--;
	}
	return (NULL);
}
