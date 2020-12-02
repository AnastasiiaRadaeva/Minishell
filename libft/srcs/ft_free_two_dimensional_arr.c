/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_two_dimensional_arr.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:14:30 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/02 09:59:34 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_two_dimensional_arr(char **array)
{
	size_t	i;

	i = -1;
	while (array[++i])
		ft_free_tmp(array[i]);
	free(array);
}
