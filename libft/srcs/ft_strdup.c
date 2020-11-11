/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 11:03:44 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/06 12:27:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*p;
	size_t	len;

	len = ft_strlen(src);
	if (!(p = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ft_strlcpy(p, src, len + 1);
	return (p);
}
