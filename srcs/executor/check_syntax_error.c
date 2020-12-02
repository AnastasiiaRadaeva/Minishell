/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:07:50 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/02 17:00:30 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	check_syntax_redirect(t_commands *cmd)
{
	if (cmd->redir->type_redir != 3)
	{
		if (!cmd->redir->cmd && cmd->redir->pipe)
		{
			if (cmd->redir->pipe->cmd)
			{
				errno = 2;
				error_case("minishell: syntax error near unexpected token ",
							"`|'\n", NULL);
				return (1);
			}
		}
		if (!cmd->redir->cmd && cmd->redir->next)
		{
			if (cmd->redir->next->cmd)
			{
				errno = 2;
				error_case("minishell: syntax error near unexpected token ",
							"`;'\n", NULL);
				return (1);
			}
		}
	}
	return (0);
}

static	int	check_syntax_next(t_commands *cmd)
{
	if (!cmd->next->cmd && cmd->next->pipe)
	{
		if (cmd->next->pipe->cmd)
		{
			errno = 2;
			error_case("minishell: syntax error near unexpected token ",
						"`;'\n", NULL);
			return (1);
		}
	}
	if (!cmd->next->cmd && cmd->next->redir)
	{
		if (cmd->next->redir->cmd)
		{
			errno = 2;
			error_case("minishell: syntax error near unexpected token ",
						"`;'\n", NULL);
			return (1);
		}
	}
	return (0);
}

static	int	check_syntax_pipe(t_commands *cmd)
{
	 if (!cmd->pipe->cmd && cmd->pipe->next)
	{
		if (cmd->pipe->next->cmd)
		{
			errno = 2;
			error_case("minishell: syntax error near unexpected token ",
						"`|'\n", NULL);
			return (1);
		}
	}
	if (!cmd->pipe->cmd && cmd->pipe->redir)
	{
		if (cmd->pipe->redir->cmd)
		{
			errno = 2;
			error_case("minishell: syntax error near unexpected token ",
						"`|'\n", NULL);
			return (1);
		}
	}
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
