/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:53:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 13:51:01 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_output(t_commands *cmd, t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	program_exit(cmd, data, 1);
}
