/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_an_array_element.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 10:48:06 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 14:05:05 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_delete_an_array_element(char ***array, size_t i)
{
	size_t	len_arr;
	char	*tmp;

	len_arr = ft_strlenarr(*array);
	if (len_arr <= i)
		return ;
	while (array[i + 1])
	{
		tmp = *(array)[i];
		*(array)[i] = *(array)[i + 1];
		ft_free_tmp(tmp);
		i++;
	}
	ft_free_tmp((*array)[i]);
}
