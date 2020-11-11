/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:43:22 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/10 15:04:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlenarr(char **array)
{
	size_t	i;
	
	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}
