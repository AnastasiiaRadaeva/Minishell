/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:38:26 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/07 15:15:15 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parser.h"

void		pipe_end(t_commands *pip, t_data *all, int fd0, int fd1)
{
	dup2(fd0, 0);
	if (fd1 != 0)
		close(fd1);
	if (fd0 != 0)
		close(fd0);
	if (pip->pipe)
	{
		close(1);
		dup2(all->fd_1, 1);
		execute_cmd_line(&pip->pipe, all);
	}
}

int			redirects(t_commands *redir)
{
	int		fd;

	if (redir)
		while (redir->redir)
		{
			if (redir->type_redir == CHAR_LESSER && redir->redir->invalid != -2)
			{
				if ((fd = open(redir->redir->cmd, O_CREAT, 0644)) == -1)
					return (1);
			}
			else
			{
				if (redir->type_redir == CHAR_GREATER &&\
												redir->redir->invalid != -2)
					fd = open(redir->redir->cmd, O_CREAT |
								O_RDWR | O_TRUNC, S_IRWXU);
				if (redir->type_redir == 3 && redir->redir->invalid != -2)
					fd = open(redir->redir->cmd, O_CREAT |
								O_RDWR | O_APPEND, S_IRWXU);
			}
			dup2(fd, (redir->type_redir == CHAR_LESSER) ? 0 : 1);
			redir = redir->redir;
		}
	return (0);
}

void		execute_cmd_line(t_commands **cmd, t_data *data)
{
	int			fd[2];
	t_commands	*pip;
	t_commands	*redirect;

	fd[0] = 0;
	fd[1] = 0;
	if ((*cmd)->cmd || (*cmd)->type_redir)
	{
		pip = (*cmd);
		redirect = (*cmd);
		if (pip->pipe)
		{
			pipe(fd);
			dup2(fd[1], 1);
		}
		selection_cmd(cmd, data, redirect);
		pipe_end(pip, data, fd[0], fd[1]);
	}
}

void		executor(t_commands *syntax_tree, t_data *data)
{
	t_commands	*next_nod;

	next_nod = syntax_tree;
	if (next_nod)
	{
		while (next_nod)
		{
			execute_cmd_line(&next_nod, data);
			dup2(data->fd_1, 1);
			dup2(data->fd_0, 0);
		}
	}
}
