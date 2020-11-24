/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:00:22 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/16 14:27:02 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t		move_pointer(t_commands *cmd, t_data *data, char *p, char *line)
{
	(void)data;
	
	char 	*n_p;

	n_p = p;
	if (*p == '\'')
	{
		if (!(cmd->invalid = (n_p = ft_strrchr(++n_p, '\'')) ? 0 : -1))
			return (n_p - line + 1);
		else
			return (ft_strlen(p));
	}
	else
	{
		if (!(cmd->invalid = (n_p = ft_strchr2(++n_p, "\"$")) ? 0 : -1))
		{
			// n_p = (*n_p == '$') ? if_dollar(data, n_p, cmd->invalid) : n_p;
			return (n_p - line + 1);
		}
		else
			return (ft_strlen(p));
	}
	return (0);
}
