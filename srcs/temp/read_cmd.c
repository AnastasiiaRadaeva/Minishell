/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:03:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/04 12:19:28 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_cmd(t_commands *cmd, char **line)
{
	if (get_next_line(0, line) < 0)
		error_output(cmd, GNL_1);
}
