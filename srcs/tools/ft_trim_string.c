/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:58:40 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/07 19:57:08 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char		*ft_trim_string(char *string, size_t size)
{
	string[size] = '\0';
	return (string);
}