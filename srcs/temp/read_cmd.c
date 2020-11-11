/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:03:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/11 11:39:21 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_cmd(t_commands *cmd, char **line)
{
	if (get_next_line(0, line) < 0)
		error_output(cmd, GNL_1);
	if (!(ft_strncmp("exit", *line, ft_strlen(*line))))
	{
		ft_free_tmp(*line);
		program_exit(cmd, 1);
	}
}
