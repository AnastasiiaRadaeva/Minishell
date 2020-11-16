/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 16:21:23 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/16 16:35:43 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	add_node(t_commands *cmd, t_data *data, char **line)
{
	if (**line == '>' || **line == '<')
	{
		cmd->redir = init_struct_commands();
		cmd = cmd->redir;
	}
	else if (**line == '|')
	{
		cmd->pipe = init_struct_commands();
		cmd = cmd->pipe;
	}
	else if (**line == ';')
	{
		cmd->next = init_struct_commands();
		cmd = cmd->next;
	}
	++*line;
	data_collection(&cmd, data, line);
}
