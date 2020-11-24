/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:25:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/24 19:25:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		init_arg(t_commands *cmd)
{
	t_list		*tmp;
	
	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;
	cmd->count_args = ft_lstsize(cmd->lst);
}

static	int		checking_cmd_for_tocken(char *word)
{
	if (!(ft_strcmp("echo", word)))
		return (CMD_ECHO);
	else if (!(ft_strcmp("cd", word)))
		return (CMD_CD);
	else if (!(ft_strcmp("pwd", word)))
		return (CMD_PWD);
	else if (!(ft_strcmp("export", word)))
		return (CMD_EXPORT);
	else if (!(ft_strcmp("unset", word)))
		return (CMD_UNSET);
	else if (!(ft_strcmp("env", word)))
		return (CMD_ENV);
	else if (!(ft_strcmp("exit", word)))
		return (CMD_EXIT);
	return (CMD_IN_PATH);
}

static int		checking_cmd(char *cmd)
{
	char 		*tmp;
	size_t		i;

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

static	void	init_cmd(t_commands *cmd)
{
	cmd->cmd = cmd->lst->content;
	cmd->invalid = checking_cmd(cmd->cmd);
	cmd->num_cmd = cmd->invalid;
}

void			init(t_commands **cmd)
{
	if (!(*cmd)->lst)
		return;
	init_cmd(*cmd);
	init_arg(*cmd);
}
