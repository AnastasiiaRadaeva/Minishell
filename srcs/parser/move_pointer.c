/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:00:40 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/09 17:07:51 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*move_pointer(char *p1, char *p2)
{
	p1 = p2;

	if (*p1 == ' ')
		return (skip_spaces(p1));
	else if (*p1 == '\'')
		return (ft_strchr(p1, '\''));
	return (p1);
}