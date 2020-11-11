/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:59:24 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/06 12:26:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup2(char **src, size_t n)
{
	char	*new_array;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!(new_array = (char *)malloc(sizeof(char) * (ft_strlen(*src) + 1))))
		return (NULL);
	while ((*src)[i] && size != n)
	{
		new_array[i] = (*src)[i];
		i++;
		size++;
	}
	new_array[i] = '\0';
	free(*src);
	return (new_array);
}
