/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:57:11 by anatashi          #+#    #+#             */
/*   Updated: 2020/09/29 16:07:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (slen < start)
		return (ft_strdup(""));
	if (len >= slen)
		len = slen - start;
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < start)
	{
		i++;
		s++;
	}
	ft_strlcpy(sub, s, len + 1);
	return (sub);
}
