/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 14:41:09 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_commands(t_commands *cmd)
{
	if (!(cmd = (t_commands *)malloc(sizeof(t_commands))))
		error_output(cmd, MALLOC_1);
	cmd->cmd = NULL;
	cmd->cmd_dir = NULL;
	cmd->arg = NULL;
	cmd->dit_find = 0;
	cmd->type_redir = 0;
	cmd->invalid = 0;
	cmd->redir = NULL;
	cmd->pipe = NULL;
	cmd->next = NULL;
}
