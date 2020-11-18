/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:22:15 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/17 16:51:49 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_var(t_commands *cmd, t_data *all)
{
	char	*tmp;

	tmp = all->envp[all->old_pwd];
	if (!(all->envp[all->old_pwd] = ft_strdup(all->envp[all->current_pwd])))
		error_output(cmd, MALLOC_11);
	free(tmp);
	tmp = all->envp[all->current_pwd];
	if (!(all->envp[all->current_pwd] = ft_strdup(cmd->lst->content)))
		error_output(cmd, MALLOC_11);
	free(tmp);
}

void	ft_cd(t_commands *cmd, t_data *all)
{
	char	*tmp_path;

	if (cmd->count_args == 0)
		cmd->lst->content = all->envp[all->home_dir] + 5;
	if (cmd->count_args == 2)
	{
		ft_putstr(CD_STR_NOT);
		error_output(cmd, cmd->lst->content);
	}
	if (cmd->count_args > 2)
		error_output(cmd, CD_MANY_ARGS);
	if (cmd->lst->content[0] == '~')
	{
		if (!(tmp_path = ft_strjoin(all->envp[all->home_dir] + 5, cmd->lst->content + 1)))
			error_output(cmd, MALLOC_5);
		free(cmd->lst->content);
		cmd->lst->content = tmp_path;
	}
	if (chdir(cmd->lst->content) != 0)
	{
		ft_putstr(CD_NO_SUCH_F_D);
		error_output(cmd, MALLOC_5);
	}
	change_var(cmd, all);
}
