/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:12:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/09 14:47:21 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_pwd(t_commands *cmd)
{
	char	path[1000];

	if (cmd->count_args != 0)
		error_output(cmd, PWD_MANY_ARGS);
	if (getcwd(path, 1000) == NULL)
		error_output(cmd, PWD_GETCWD);
	return (path);
}