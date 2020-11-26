/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:07:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/25 19:13:31 by anatashi         ###   ########.fr       */
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
	char	**split_path;
	char	*tmp_cmd;
	char	**argv_for_execve;

	i = -1;
	tmp_cmd = ft_strjoin("/", (*cmd)->cmd);
	split_path = ft_split((*data)->envp[(*data)->path] + 5, ':');
	argv_for_execve = NULL;
	argv_for_execve = creat_dimens_arr_for_execve(*cmd);
	pid = fork();
	// signal(SIGINT, )   - ?
	if (!pid)
	{
		while (split_path[++i])
		{
			split_path[i] = ft_strjoin_gnl(&split_path[i], tmp_cmd);
			if ((execve(split_path[i], argv_for_execve, (*data)->envp)) == -1)
			{
				if (errno != 2)
					exit(1);
			}
		}
	}
	else
		wait(&pid);
	ft_free_tmp(tmp_cmd);
	ft_free_two_dimensional_arr(split_path);
	ft_free_two_dimensional_arr(argv_for_execve);
}
