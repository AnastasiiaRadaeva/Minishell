/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_selection_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:12:38 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/09 14:30:54 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parser.h"

static void	error_with_status(t_commands *cmd)
{
	if (!*cmd->cmd)
		return ;
	error_case("minishell: ", cmd->cmd, ": command not found\n");
	g_global_status = 127;
}

void		selection_cmd(t_commands **cmd, t_data *data,
								t_commands *redirect)
{
	if (redirects(redirect))
		return ;
	if ((*cmd)->num_cmd == CMD_PWD)
		ft_pwd((*cmd), data);
	else if ((*cmd)->num_cmd == CMD_ENV)
		ft_env((*cmd), data);
	else if ((*cmd)->num_cmd == CMD_CD)
		ft_cd(cmd, data);
	else if ((*cmd)->num_cmd == CMD_ECHO)
		ft_echo(*cmd);
	else if ((*cmd)->num_cmd == CMD_EXPORT)
		ft_export(cmd, &data);
	else if ((*cmd)->num_cmd == CMD_UNSET)
		ft_unset(cmd, &data);
	else if ((*cmd)->num_cmd == CMD_IN_PATH)
		ft_check_cmd_in_path(cmd, &data);
	else if ((*cmd)->num_cmd == CMD_EXIT)
		ft_exit(*cmd, data);
	else if ((*cmd)->num_cmd == CMD_ERROR)
		error_with_status(*cmd);
}
