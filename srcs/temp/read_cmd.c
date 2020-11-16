/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:03:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/12 22:13:15 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_cmd(char **line)
{
	if (get_next_line(0, line) < 0)
		error_output(NULL, GNL_1);
	if (!(ft_strncmp("exit", *line, ft_strlen(*line))))
	{
		ft_free_tmp(*line);
		program_exit(NULL, 1);
	}
}
