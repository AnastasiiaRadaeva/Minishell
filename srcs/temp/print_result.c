/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:00 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 12:39:02 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_result(t_commands *cmd, char *line)
{
	if (cmd)
	{

	}
	else
	{
		ft_putstr(CMD_NO_FOUND);
		ft_putendl(line);
		// ft_free_tmp(line);
	}
}