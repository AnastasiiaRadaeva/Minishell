/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:38:26 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/26 18:09:32 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"
#include "parser.h"

void		pipe_end(t_commands *pip, t_data *all, int fd0, int fd1)
{
	dup2(fd0, 0);
	close(fd1);
	close(fd0);
	if (pip->pipe)
	{
		close(1);
		dup2(all->fd_1, 1);
		execute_cmd_line(pip->pipe, all);
	}
}

int			redirects(t_commands *redir)
{
	int			fd;

	while (redir->redir)
	{
		if (redir->type_redir == CHAR_LESSER && redir->redir->invalid != -2)
		{
			if ((fd = open(redir->redir->cmd, O_CREAT, 0644)) == -1)
				return (1);
		}
		else
		{
			if (redir->type_redir == CHAR_GREATER && redir->redir->invalid != -2)
				fd = open(redir->redir->cmd, O_CREAT |
							O_RDWR | O_TRUNC, S_IRWXU);
			if (redir->type_redir == 3 && !redir->redir->invalid)
				fd = open(redir->redir->cmd, O_CREAT |
							O_RDWR | O_APPEND, S_IRWXU);
		}
		dup2(fd, (redir->type_redir == CHAR_LESSER) ? 0 : 1);
		redir = redir->redir;
	}
	return (0);
}

#if 0
void			give_env(t_data *data)
{
	int			i;

	i = -1;
	while (data->envp[++i])
	{
		if (ft_strchr(data->envp[i], '='))
		{
			ft_putendl(data->envp[i]);
		}
	}
}
#endif

void			selection_cmd(t_commands *cmd, t_data *data,
								t_commands *redirect, t_commands *pip)
{
	// #if 0
	(void)pip;
	// #endif
	if (redirects(redirect))
		return;
	if (cmd->num_cmd == CMD_PWD)
		ft_pwd(cmd, data);
	else if (cmd->num_cmd == CMD_ENV)
		// give_env(data);
		ft_env(cmd, data);
	else if (cmd->num_cmd == CMD_CD)
		ft_cd(&cmd, data);
	else if (cmd->num_cmd == CMD_ECHO)
		ft_echo(cmd);
	else if (cmd->num_cmd == CMD_EXPORT)
		ft_export(&cmd, &data);
	else if (cmd->num_cmd == CMD_UNSET)
		ft_unset(&cmd, &data);
	else if (cmd->num_cmd == CMD_IN_PATH)
		ft_check_cmd_in_path(&cmd, &data);	
}

void			execute_cmd_line(t_commands *cmd, t_data *data)
{
	int			fd[2];
	t_commands	*pip;
	t_commands	*redirect;

	if (cmd->cmd)
	{
		pip = cmd;
		redirect = cmd;
		if (pip->pipe)
		{
			pipe(fd);
			dup2(fd[1], 1);
		}
		selection_cmd(cmd, data, redirect, pip);
		pipe_end(pip, data, fd[0], fd[1]);
	}
}

void	executor(t_commands *syntax_tree, t_data *data)
{
	if (syntax_tree && syntax_tree->invalid != CMD_ERROR)
	{
		while (syntax_tree && syntax_tree->invalid != CMD_ERROR)
		{
			execute_cmd_line(syntax_tree, data);
			syntax_tree = syntax_tree->next;
			dup2(data->fd_1, 1);
			dup2(data->fd_0, 0);
		}
	}
	else
	{
		ft_putendl("Invalid command");
		ft_free_tmp(data->error_string);
		if (!(data->error_string =ft_strdup("127")))
			error_output(syntax_tree, data, NULL);
	}	
}