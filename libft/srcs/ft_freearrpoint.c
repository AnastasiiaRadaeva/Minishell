/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearrpoint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 08:25:33 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/23 08:30:18 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearrpoint(char **nstr, size_t j)
{
	while (j--)
		free(nstr[j]);
	free(nstr);
}
