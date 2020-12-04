/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:07:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/03 21:19:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <errno.h>
#include "parser.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static	char	**creat_dimens_arr_for_execve(t_commands *cmd)
{
	char		**argv_for_execve;
	int			i;
	t_list		*tmp;
	
	i = 0;
	tmp = cmd->lst;
	argv_for_execve = (char **)malloc(sizeof(char *) * cmd->count_args + 2);
	argv_for_execve[i] = cmd->cmd;
	i++;
	while (tmp)
	{
		argv_for_execve[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	argv_for_execve[i] = NULL;
	return (argv_for_execve);
}

void		ft_check_cmd_in_path(t_commands **cmd, t_data **data)
{
	
	pid_t	pid;
	char	**argv_for_execve;
	char	*tmp;
	int		status;

	argv_for_execve = NULL;
	argv_for_execve = creat_dimens_arr_for_execve(*cmd);
	tmp = (*cmd)->cmd;
	(*cmd)->cmd = ft_strjoin((*cmd)->cmd_dir, (*cmd)->cmd);
	ft_free_tmp(tmp);
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve((*cmd)->cmd, argv_for_execve, (*data)->envp);
		exit(EXIT_FAILURE);
	}
	else
	{
		signal(SIGINT, signal_handler_2);
		signal(SIGQUIT, signal_handler_2);

		if (waitpid(pid, &status, WUNTRACED) == -1)
			error_output(*cmd, *data, (strerror(errno)));
		if (WIFEXITED(status))
			global_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			global_status = 128 + WTERMSIG(status);
		else if (WIFSTOPPED(status))
			global_status = WSTOPSIG(status);
		else if (WIFCONTINUED(status))
			ft_putendl("continued");
		free(argv_for_execve);
	}
}
