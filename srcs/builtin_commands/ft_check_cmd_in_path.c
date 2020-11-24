/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd_in_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:07:39 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/24 21:03:10 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void		ft_check_cmd_in_path(t_commands **cmd, t_data **data)
{
	pid_t	pid;
	int		i;
	char	**split_path;
	char	*tmp_cmd;
	char	**argv_for_execve;
	int		status;

	i = -1;
	tmp_cmd = ft_strjoin("/", (*cmd)->cmd);
	split_path = ft_split((*data)->envp[(*data)->path] + 5, ':');
	argv_for_execve = NULL;
	pid = fork();
	if ((*cmd)->lst)
		argv_for_execve = create_two_dimensional_array_from_lst((*cmd)->lst);
	ft_putendl(argv_for_execve[0]);
	if (!pid) 
	{
		while (split_path[++i])
		{
			split_path[i] = ft_strjoin_gnl(&split_path[i], tmp_cmd);
			execve(split_path[i], argv_for_execve, (*data)->envp);
		}
		// char *s = "/bin/ls";
		
		// execve(s, argv_for_execve, (*data)->envp);
	}
	else
	{	
		wait(&pid);
		status = WEXITSTATUS(pid);
	}
}