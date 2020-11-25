/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:07:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/25 11:59:50 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static	char	**creat_dimens_arr_for_execve(t_commands *cmd)
{
	char		**argv_for_execve;
	int			i;
	t_list		*tmp;
	
	i = 0;
	tmp = cmd->lst;
	argv_for_execve = (char **)malloc(sizeof(char *) * cmd->count_args + 2);
	argv_for_execve[i++] = cmd->cmd;
	while (tmp)
	{
		argv_for_execve[i++] = tmp->content;
		tmp = tmp->next;
	}
	argv_for_execve[i] = NULL;
	return (argv_for_execve);
}

void		ft_check_cmd_in_path(t_commands **cmd, t_data **data)
{
	// #if 0
	pid_t	pid;
	int		i;
	char	**split_path;
	char	*tmp_cmd;
	char	**argv_for_execve;

	i = -1;
	tmp_cmd = ft_strjoin("/", (*cmd)->cmd);
	split_path = ft_split((*data)->envp[(*data)->path] + 5, ':');
	argv_for_execve = NULL;
	pid = fork();
	// signal(SIGINT, )   - ?
	argv_for_execve = creat_dimens_arr_for_execve(*cmd);
	if (!pid) 
	{
		// while (split_path[++i])
		// {
			split_path[3] = ft_strjoin_gnl(&split_path[3], tmp_cmd);
			execve(split_path[3], argv_for_execve, (*data)->envp);
		// }
		// char *s = "/bin/ls";
		
		// execve(s, argv_for_execve, (*data)->envp);
	}
	wait(&pid);
	// #endif
}
