/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:53:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/17 16:13:41 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program_exit.h"

void	error_output(t_commands *cmd, t_data *data, char *str)
{
	ft_putendl_fd(str, 2);
	program_exit(cmd, data, 0);
}