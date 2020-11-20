/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:12:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/20 16:04:32 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "program_exit.h"

char	*ft_pwd(t_commands *cmd, t_data *data)
{
	char	path[1000];

	if (cmd->count_args != 0)
		error_output(cmd, data, PWD_MANY_ARGS);
	if (getcwd(path, 1000) == NULL)
		error_output(cmd, data, PWD_GETCWD);
	return (path);
}