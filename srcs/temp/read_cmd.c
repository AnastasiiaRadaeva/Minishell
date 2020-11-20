/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:03:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 19:54:37 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_cmd(t_data *data, char **line)
{
	if (get_next_line(0, line) < 0)
		error_output(NULL, data, GNL_1);
	if (!(ft_strncmp("exit", *line, ft_strlen(*line))))
	{
		ft_free_tmp(*line);
		program_exit(NULL, data, 1);
	}
}
