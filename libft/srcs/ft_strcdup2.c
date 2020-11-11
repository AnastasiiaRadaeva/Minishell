/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:20:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/06 12:15:38 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcdup2(char **src, int c)
{
	char	*new_array;
	size_t	i;
	size_t	len;

	i = -1;
	len = *src - ft_strchr(*src, c);
	if (!(new_array = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while ((*src)[++i] && i != len)
		new_array[i] = (*src)[i];
	new_array[i] = '\0';
	free(*src);
	return (new_array);
}
