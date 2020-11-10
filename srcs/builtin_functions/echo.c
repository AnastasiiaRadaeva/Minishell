/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:48:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/09 17:35:09 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_join_all_args(t_commands *cmd, int index)
{
	char	*line_for_print;
	char	*temp_line;
	int		count_loops;

	if (!(line_for_print = ft_strdup("")))
		error_output(cmd, MALLOC_6);
	count_loops = cmd->count_args - 1;
	while (index < count_loops)
	{
		temp_line = line_for_print;
		if (!(line_for_print = ft_strjoin(line_for_print, " ")))
			error_output(cmd, MALLOC_6);
		free(temp_line);
		temp_line = line_for_print;
		if (!(line_for_print = ft_strjoin(line_for_print, cmd->arg[index])))
			error_output(cmd, MALLOC_6);
		free(temp_line);
		index++;
	}
	return (line_for_print);
}

char	*ft_echo(t_commands *cmd)
{
	int	index;
	char	end_of_string;
	char	*line_for_print;

	index = 0;
	end_of_string = '\n';
	if (ft_strcmp(cmd->arg[0], "-n") == 0)
	{
		index++;
		end_of_string = '\0';
	}
	line_for_print = ft_join_all_args(cmd, index);
	return (line_for_print);
}
