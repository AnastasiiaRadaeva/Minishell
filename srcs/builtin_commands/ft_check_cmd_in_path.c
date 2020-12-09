/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:07:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 14:30:54 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <errno.h>
#include "parser.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static char	**creat_dimens_arr_for_execve(t_commands *cmd)
{
	char		**argv_for_execve;
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = cmd->lst;
	argv_for_execve = (char **)malloc(sizeof(char *) * (cmd->count_args + 2));
	argv_for_execve[i] = ft_strdup(cmd->cmd);
	i++;
	while (tmp)
	{
		argv_for_execve[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	argv_for_execve[i] = NULL;
	return (argv_for_execve);
}

static void	if_childpid(t_data **data, t_commands **cmd)
{
	char	**argv_for_execve;
	char	*command;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	argv_for_execve = creat_dimens_arr_for_execve(*cmd);
	command = ft_strjoin((*cmd)->cmd_dir, (*cmd)->cmd);
	execve(command, argv_for_execve, (*data)->envp);
	ft_free_tmp(command);
	ft_free_two_dimensional_arr(argv_for_execve);
	exit(EXIT_FAILURE);
}

void		ft_check_cmd_in_path(t_commands **cmd, t_data **data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
		if_childpid(data, cmd);
	else
	{
		signal(SIGINT, signal_handler_2);
		signal(SIGQUIT, signal_handler_2);
		if (waitpid(pid, &status, WUNTRACED) == -1)
			error_output(*cmd, *data, (strerror(errno)));
		if (WIFEXITED(status))
			g_global_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_global_status = 128 + WTERMSIG(status);
		else if (WIFSTOPPED(status))
			g_global_status = WSTOPSIG(status);
	}
}
