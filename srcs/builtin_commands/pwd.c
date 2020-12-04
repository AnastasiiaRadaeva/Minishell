/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:12:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/04 18:25:45 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pwd(t_commands *cmd, t_data *all)
{
	if (!(all->envp[all->current_pwd]))
		error_output(cmd, all, PWD_GETCWD);
	ft_putendl(all->envp[all->current_pwd] + 4);
	exit(EXIT_SUCCESS);
}

void		ft_pwd(t_commands *cmd, t_data *all)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pwd(cmd, all);
	}
	else
	{
		signal(SIGINT, signal_handler_2);
		signal(SIGQUIT, signal_handler_2);
		if (waitpid(pid, &status, WUNTRACED) == -1)
			error_output(cmd, NULL, strerror(errno));
		if (WIFEXITED(status))
			global_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			global_status = 128 + WTERMSIG(status);
		else if (WIFSTOPPED(status))
			global_status = WSTOPSIG(status);
		else if (WIFCONTINUED(status))
			ft_putendl("continued");
	}
}
