/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:02:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 20:04:29 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void freeing_memory_from_struct_commands(t_commands *cmd)
{
	if (cmd)
	{
		ft_free_tmp(cmd->cmd);
		ft_free_tmp(cmd->cmd_dir);
		// ft_free_two_dimensional_arr(cmd->arg);
		freeing_memory_from_struct_commands(cmd->redir);
		freeing_memory_from_struct_commands(cmd->pipe);
		freeing_memory_from_struct_commands(cmd->next);
	}
}

int		program_exit(t_commands *cmd, t_data *data, int num)
{
	if (cmd)
		freeing_memory_from_struct_commands(cmd);
	if (data)
		;
	// sleep(1000);
	exit(num);
}
