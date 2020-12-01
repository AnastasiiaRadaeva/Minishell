/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:07:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/01 15:58:14 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <errno.h>
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
	int		i;
	char	**argv_for_execve;
	char	*tmp;
	// int		status;
	i = -1;
	argv_for_execve = NULL;
	argv_for_execve = creat_dimens_arr_for_execve(*cmd);
	// signal(SIGINT, )   - ?

	tmp = (*cmd)->cmd;
	(*cmd)->cmd = ft_strjoin((*cmd)->cmd_dir, (*cmd)->cmd);
	ft_free_tmp(tmp);
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve((*cmd)->cmd, argv_for_execve, (*data)->envp);
		exit(1);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		wait(&pid);
		// write(1, &status, 1);
	}
	// ft_free_two_dimensional_arr(argv_for_execve);
}