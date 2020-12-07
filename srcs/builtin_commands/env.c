/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:20:39 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 11:16:46 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env(t_commands *cmd, t_data *all)
{
	int		i;

	i = -1;
	if (cmd->count_args > 0)
	{
		error_case("env: ", cmd->lst->content, ": No such file or directory\n");
		exit(127);
	}
	else
		while (all->envp[++i])
			ft_putendl(all->envp[i]);
	exit(EXIT_SUCCESS);
}

void		ft_env(t_commands *cmd, t_data *all)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		env(cmd, all);
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
