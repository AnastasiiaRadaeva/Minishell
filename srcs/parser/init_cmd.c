/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:25:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/19 20:59:04 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			checking_cmd_for_tocken(char *word)
{
	if (!(ft_strcmp("echo", word)))
		return (1);
	else if (!(ft_strcmp("cd", word)))
		return (2);
	else if (!(ft_strcmp("pwd", word)))
		return (3);
	else if (!(ft_strcmp("export", word)))
		return (4);
	else if (!(ft_strcmp("unset", word)))
		return (5);
	else if (!(ft_strcmp("env", word)))
		return (6);
	else if (!(ft_strcmp("exit", word)))
		return (7);
	return (-1);
}

static int	checking_cmd(char *cmd)
{
	char 	*tmp;
	size_t	i;

	i = -1;
	tmp = cmd;
	while (tmp[++i])
	{
		if (ft_isalpha(tmp[i]))
			if (tmp[i] >= 'A' && tmp[i] <= 'Z')
				tmp[i] += 32;
	}
	if (tmp[i])
		return (-1);
	return (checking_cmd_for_tocken(tmp));
}

void 		init_cmd(t_commands *cmd)
{
	cmd->cmd = cmd->lst->content;
	cmd->invalid = checking_cmd(cmd->cmd);
	cmd->num_cmd = cmd->invalid > 0 ? cmd->invalid : 0;
}