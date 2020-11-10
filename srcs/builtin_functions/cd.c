/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:22:15 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/09 16:34:03 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//добавить изменение переменых среды

void	ft_cd(t_commands *cmd, t_other *add)
{
	char	*tmp_path;

	if (cmd->count_args == 0)
		cmd->arg[0] = add->home;
	if (cmd->count_args == 2)
	{
		ft_putstr(CD_STR_NOT);
		error_output(cmd, cmd->arg[0]);
	}
	if (cmd->count_args > 2)
		error_output(cmd, CD_MANY_ARGS);
	if (cmd->arg[0][0] == '~')
	{
		if (!(tmp_path = ft_strjoin(add->home, cmd->arg[0] + 1)))
			error_output(cmd, MALLOC_5);
		free(cmd->arg[0]);
		cmd->arg[0] = tmp_path;
	}
	if (chdir(cmd->arg[0]) != 0)
	{
		ft_putstr(CD_NO_SUCH_F_D);
		error_output(cmd, MALLOC_5);
	}
}
