/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_an_array_element.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:48:06 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/10 16:44:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_delete_an_array_element(char ***array, size_t i)
{
	size_t	len_arr;
	char	*tmp;

	len_arr = ft_strlenarr(*array);
	if (len_arr <= i)
		return;
	while (array[i + 1])
	{
		tmp = *(array)[i];
		*(array)[i] = *(array)[i + 1];
		i++;
	}
	ft_free_tmp((*array)[i]);
}
