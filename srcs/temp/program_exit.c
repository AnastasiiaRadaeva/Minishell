/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:02:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/07 11:29:00 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freeing_memory_from_struct_data(t_data *data)
{
	ft_free_two_dimensional_arr(data->envp);
	free(data);
	data = NULL;
}

void	freeing_memory_from_lst(t_list **lst)
{
	t_list	*dell;
	t_list	*plst;

	if (lst)
	{
		plst = *lst;
		while (plst)
		{
			dell = plst;
			plst = plst->next;
			free(dell);
			dell = NULL;
		}
		*lst = NULL;
	}
}

void	freeing_memory_from_struct_commands(t_commands *cmd)
{
	if (cmd)
	{
		ft_free_tmp(cmd->cmd);
		ft_free_tmp(cmd->cmd_dir);
		ft_lstclear(&cmd->lst, ft_lstdelone_f);
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
	sleep(10000000);
	exit(num);
}
