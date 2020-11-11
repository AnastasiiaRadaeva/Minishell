/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 09:26:42 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/06 12:25:59 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *src, size_t n)
{
	char	*new_array;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!(new_array = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i] && size != n)
	{
		new_array[i] = src[i];
		i++;
		size++;
	}
	new_array[i] = '\0';
	return (new_array);
}
