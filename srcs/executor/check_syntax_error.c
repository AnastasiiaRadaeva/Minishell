/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:07:50 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/05 14:12:21 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static	int	return_error_case(int err, char *str_err)
{
	errno = err;
	
	error_case("minishell: syntax error near unexpected token ",
							str_err, NULL);
	return (1);
}

static int	check_syntax_redirect(t_commands *cmd)
{
	if (cmd->redir->type_redir != 3)
	{
		if (!cmd->redir->cmd && cmd->redir->pipe)
		{
			if (cmd->redir->pipe->cmd)
				return_error_case(2, "`|'\n");
		}
		else if (!cmd->redir->cmd && cmd->redir->next)
		{
			if (cmd->redir->next->cmd)
				return_error_case(2, "`;'\n");
		}
		else if (!cmd->redir->cmd && cmd->redir->redir)
		{
			if (!cmd->redir->redir->cmd)
				return_error_case(2, "`>>'\n");
		}
		else if (!cmd->redir->cmd && !cmd->redir->next &&
			!cmd->redir->pipe && !cmd->redir->redir)
			return_error_case(2, "`>'");
	}
	return (0);
}

static	int	check_syntax_next(t_commands *cmd)
{
	if (!cmd->next->cmd && cmd->next->pipe)
	{
		if (cmd->next->pipe->cmd)
			return_error_case(2, "`;'\n");
	}
	else if (!cmd->next->cmd && cmd->next->redir)
	{
		if (cmd->next->redir->cmd)
			return_error_case(2, "`;'\n");
	}
	else if (!cmd->next->cmd && cmd->next->next)
	{
		if (!cmd->next->next->cmd)
			return_error_case(2, "`;;'\n");
	}
	else if (!cmd->next->cmd && !cmd->next->next && !cmd->next->pipe &&
			!cmd->next->redir)
		return_error_case(2, "`;'\n");
	return (0);
}

static	int	check_syntax_pipe(t_commands *cmd)
{
	if (!cmd->pipe->cmd && cmd->pipe->next)
	{
		if (cmd->pipe->next->cmd)
			return_error_case(2, "`|'\n");
	}
	else if (!cmd->pipe->cmd && cmd->pipe->redir)
	{
		if (cmd->pipe->redir->cmd)
			return_error_case(2, "`|'\n");
	}
	else if (!cmd->pipe->cmd && cmd->pipe->pipe)
	{
		if (!cmd->pipe->pipe->cmd)
			return_error_case(2, "`||'\n");
	}
	else if (!cmd->pipe->cmd && !cmd->pipe->next && !cmd->pipe->pipe
			&& !cmd->pipe->redir)
		return_error_case(2, "`|'\n");
	return (0);
}

int			check_syntax_error(t_commands *cmd)
{

	if (cmd->redir)
		return (check_syntax_redirect(cmd));
	if (cmd->next)
		return (check_syntax_next(cmd));
	if (cmd->pipe)
		return (check_syntax_pipe(cmd));
	return (0);
}
