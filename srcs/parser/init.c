/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:25:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/07 15:52:55 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "dirent.h"
#include <sys/types.h>

static void	init_arg(t_commands *cmd)
{
	t_list	*tmp;

	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;
	cmd->count_args = ft_lstsize(cmd->lst);
}

static void	init_cmd(t_commands *cmd, t_data *data)
{
	cmd->cmd = cmd->lst->content;
	cmd->invalid = checking_cmd(cmd, data->envp[data->path]);
	cmd->num_cmd = cmd->invalid;
}

void		init(t_commands **cmd, t_data *data)
{
	if (!(*cmd)->lst)
		return ;
	init_cmd(*cmd, data);
	init_arg(*cmd);
}
