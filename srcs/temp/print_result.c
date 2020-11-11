/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:38:00 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/11 11:39:17 by kbatwoma         ###   ########.fr       */
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
		ft_free_tmp(line);
	}
}

//kbatwoma
// static void	free_array(char **array)
// {
// 	int index;

// 	index = 0;
// 	while(array[index])
// 	{
// 		free(array[index]);
// 		index++;
// 	}
// }

// static void	free_cmd(t_commands **cmd)
// {
// 	t_commands	*temp;

// 	while (*cmd)
// 	{
// 		if ((*cmd)->cmd)
// 			free((*cmd)->cmd);
// 		if ((*cmd)->cmd_dir)
// 			free((*cmd)->cmd_dir);
// 		if ((*cmd)->arg)
// 			free_array((*cmd)->arg);
// 		if ((*cmd)->pipe)
// 			temp = (*cmd)->pipe;
// 		if ((*cmd)->redir)
// 			temp = (*cmd)->redir;
// 		if ((*cmd)->next)
// 			temp = (*cmd)->next;
// 		free(*cmd);
// 		cmd = &temp;
// 	}
// }

// static	void freeing_memory_from_struct_commands(t_commands *cmd)
// {
// 	if (cmd)
// 	{
// 		ft_free_tmp(cmd->cmd);
// 		ft_free_tmp(cmd->cmd_dir);
// 		ft_free_two_dimensional_arr(cmd->arg);
// 		freeing_memory_from_struct_commands(cmd->redir);
// 		freeing_memory_from_struct_commands(cmd->pipe);
// 		freeing_memory_from_struct_commands(cmd->next);
// 	}
// }
#if 0
void	print_result(t_commands **cmd, char *line)
{
	t_commands	*tmp;

	tmp = *cmd;
	if (*cmd)
	{
		ft_putendl(tmp->cmd);
		while (tmp->next || tmp->pipe || tmp->redir)
		{
			if (tmp->next)
				tmp = tmp->next;
			if (tmp->pipe)
				tmp = tmp->pipe;
			if (tmp->redir)
				tmp = tmp->redir;
			ft_putendl(tmp->cmd);
		}
		// freeing_memory_from_struct_commands(*cmd);
	}
	else
	{
		ft_putstr(CMD_NO_FOUND);
		ft_putendl(line);
		// ft_free_tmp(line);
	}
}
#endif