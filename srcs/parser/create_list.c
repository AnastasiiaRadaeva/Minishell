/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 17:04:33 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_comand_line(t_commands *cmd, char **old_line, char **new_line)
{
	if (!(*new_line = ft_strtrim(*old_line, "\t\n\v\f\r  ")))
		error_output(cmd, MALLOC_2);
}


void	create_list(t_commands *cmd, char **line, char **new_line)
{
	init_struct_commands(cmd);
	ft_comand_line(cmd, line, new_line);
	// ft_free_tmp(line);
	// ft_spec_symb
	// return (cmd);
}