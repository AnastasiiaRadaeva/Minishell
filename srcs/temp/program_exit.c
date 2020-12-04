/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:02:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/04 11:56:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freeing_memory_from_struct_data(t_data *data)
{
	ft_free_two_dimensional_arr(data->envp);
	free(data);
	data = NULL;
}

void	freeing_memory_from_struct_commands(t_commands *cmd)
{
	if (cmd)
	{
		ft_free_tmp(cmd->cmd);
		ft_free_tmp(cmd->cmd_dir);
		ft_lstclear(&cmd->lst, ft_lstdelone_f);
		free(cmd->lst);
		// cmd->lst = NULL;
		// if (cmd->previous)
		// 	free(cmd->previous);
		freeing_memory_from_struct_commands(cmd->redir);
		freeing_memory_from_struct_commands(cmd->pipe);
		freeing_memory_from_struct_commands(cmd->next);
		free(cmd);
		cmd = NULL;
	}
}

int		program_exit(t_commands *cmd, t_data *data, int num)
{
	if (cmd)
		freeing_memory_from_struct_commands(cmd);
	if (data)
		freeing_memory_from_struct_data(data);
	exit(num);
}
