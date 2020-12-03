/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:15:19 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/03 17:13:34 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_commands *cmd, t_data *all)
{
	int	i;

	i = -1;
	ft_putendl("exit");
	if (cmd->count_args == 0)
		program_exit(cmd, all, global_status);
	else if (cmd->count_args > 0)
	{
		while (((char *)cmd->lst)[++i])
			if (ft_isdigit(((char *)cmd->lst)[++i]) == 0)
			{
				error_case("minishell: exit: ", (char *)cmd->lst, ": numeric argument required\n");
				program_exit(cmd, all, global_status);
			}
		if (cmd->count_args == 1)
		{
			if ((i = ft_atoi((char *)cmd->lst)) > 255)
				i -= 256;
			global_status = i;
			program_exit(cmd, all, global_status);	
		}
		else if (cmd->count_args > 1)
			error_case("minishell: ", "exit: ", "numeric argument required\n");
		global_status = 1;
	}	
}