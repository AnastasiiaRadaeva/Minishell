/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:55:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 21:55:54 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		term(int	toke_type, char **bufferptr)
{
	if (!curtok)
		return (0);
	if (curtok->type == toke_type)
	{
		if (bufferptr)
			*bufferptr = ft_strdup(curtok->data);
		curtok = curtok->next;
		return (1);
	}
	curtok = curtok->next;
	return (0);
}
