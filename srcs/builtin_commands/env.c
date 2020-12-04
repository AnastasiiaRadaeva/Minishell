/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:20:39 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/03 22:46:53 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env(t_commands *cmd, t_data *all)
{
	int		i;
	// char	*string;
	// char	*temp_str;

	if (cmd->count_args > 0)
	{
		error_case("env: ", cmd->lst->content, ": No such file or directory\n");
		exit(EXIT_FAILURE);
	}
	else
	{		
		// if (!(string = ft_strdup("")))
		// 	error_output(cmd,  all, "malloc: ft_env");
		// i = 0;
		// while (all->envp[i])
		// {
		// 	temp_str = string;
		// 	if (!(string = ft_strjoin(string, all->envp[i])))
		// 		error_output(cmd, all, "malloc: ft_env");
		// 	free(temp_str);
		// 	temp_str = string;
		// 	if (!(string = all->envp[++i] ? ft_strjoin(string, "\n") : string))
		// 		error_output(cmd, all, "malloc: ft_env");
		// 	if (ft_strcmp(temp_str, string) != 0)
		// 		free(temp_str);
		// }
		// ft_putendl(string);
		i = -1;
		while (all->envp[++i])
			ft_putendl(all->envp[i]);
	}
}

void	ft_env(t_commands *cmd, t_data *all)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		env(cmd, all);
		exit(EXIT_SUCCESS);
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
