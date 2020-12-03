/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:48:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/03 14:24:10 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static char	*ft_join_all_args(t_commands *cmd, t_list *start, int flag)
{
	char	*line_for_print;
	char	*temp_line;

	if (!(line_for_print = ft_strdup("")))
		error_output(cmd, NULL, MALLOC_6);
	if (cmd->count_args > 0)
		while (start)
		{
			temp_line = line_for_print;
			if (!(line_for_print = ft_strjoin(line_for_print, start->content)))
				error_output(cmd, NULL, MALLOC_6);
			free(temp_line);
			temp_line = line_for_print;
			if (!(line_for_print = start->next ? ft_strjoin(line_for_print, " ")\
									 : line_for_print))
					error_output(cmd, NULL, MALLOC_6);
			if (ft_strcmp(temp_line, line_for_print) != 0)
				free(temp_line);
			start = start->next;
		}
	if (flag == 0)
		line_for_print = ft_strjoin_gnl(&line_for_print, "\n");
	return (line_for_print);
}

static void	echo(t_commands *cmd)
{
	int		flag;
	char	*print_line;
	t_list	*start;

	flag = 0;
	start = cmd->lst;
	if (cmd->count_args > 0)
	{
		if (ft_strcmp(cmd->lst->content, "-n") == 0)
		{
			flag = 1;
			start = cmd->lst->next;
			cmd->count_args--;
		}
		else if (!ft_strcmp(cmd->lst->content, "$?"))
		{
			ft_putnbr_fd(global_status, 0);
			write(1, "\n", 1);
			return;
		}
	}
	print_line = ft_join_all_args(cmd, start, flag);
	ft_putstr(print_line);
	ft_free_tmp(print_line);
}

void	ft_echo(t_commands *cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		echo(cmd);
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
			global_status = WTERMSIG(status);
		else if (WIFSTOPPED(status))
			global_status = WSTOPSIG(status);
		else if (WIFCONTINUED(status))
			ft_putendl("continued");
	}
}
