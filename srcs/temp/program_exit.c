/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:02:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/03 18:25:59 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freeing_memory_from_struct_commands(t_commands *cmd)
{
	// t_list	*tmp;

	if (cmd)
	{
		
		// ft_free_tmp(cmd->cmd_dir);
		// tmp = cmd->lst;
		// while(tmp)
		// {
		// 	ft_lstdelone(tmp, NULL);
		// 	tmp = tmp->next;
		// }
		// free(tmp);
		// tmp = NULL;
		// if (cmd->previous)
		// 	free(cmd->previous);
		// freeing_memory_from_struct_commands(cmd->redir);
		// freeing_memory_from_struct_commands(cmd->pipe);
		// freeing_memory_from_struct_commands(cmd->next);
		// free(cmd);
		// cmd = NULL;
	}
}

int		program_exit(t_commands *cmd, t_data *data, int num)
{
	if (cmd)
		freeing_memory_from_struct_commands(cmd);
	if (data)
		NULL;
	// sleep(1000);
	exit(num);
}
