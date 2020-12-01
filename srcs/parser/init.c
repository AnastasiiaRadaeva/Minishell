/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:25:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/01 16:00:42 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "dirent.h"
#include <sys/types.h>

static void		init_arg(t_commands *cmd)
{
	t_list		*tmp;
	
	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;
	cmd->count_args = ft_lstsize(cmd->lst);
}

int			check_cmd_in_path(t_commands *cmd, char *tmp, char *path)
{
	DIR		*dir;
	struct	dirent *entry;
	int		i;
	int		j;
	char	**split_path;
	
	i = -1;
	split_path = ft_split(path + 5, ':');
	while (split_path[++i])
	{
		dir = opendir(split_path[i]);
		while ((entry = readdir(dir)))
		{
			if (!ft_strcmp(entry->d_name, tmp))
			{
				j = i + 1;
				cmd->cmd = ft_strjoin("/",cmd->cmd);
				cmd->cmd_dir = split_path[i--];
				while (i)
					ft_free_tmp(split_path[i--]);
				while (split_path[j])
					ft_free_tmp(split_path[j++]);
				free(split_path);
				return (0);
			}
		}
	}
	ft_free_two_dimensional_arr(split_path);
	return (1);
}

static	int		checking_cmd_for_tocken(t_commands *cmd, char *tmp, char *path)
{
	if (!(ft_strcmp("echo", tmp)))
		return (CMD_ECHO);
	else if (!(ft_strcmp("cd", tmp)))
		return (CMD_CD);
	else if (!(ft_strcmp("pwd", tmp)))
		return (CMD_PWD);
	else if (!(ft_strcmp("export", tmp)))
		return (CMD_EXPORT);
	else if (!(ft_strcmp("unset", tmp)))
		return (CMD_UNSET);
	else if (!(ft_strcmp("env", tmp)))
		return (CMD_ENV);
	else if (!(ft_strcmp("exit", tmp)))
		return (CMD_EXIT);
	else if (!check_cmd_in_path(cmd, tmp, path))
		return (CMD_IN_PATH);
	return(CMD_ERROR);
}

static int		checking_cmd(t_commands *cmd, char *path)
{
	char 		*tmp;
	size_t		i;

	i = -1;
	tmp = cmd->cmd;
	while (tmp[++i])
	{
		if (ft_isalpha(tmp[i]))
			if (tmp[i] >= 'A' && tmp[i] <= 'Z')
				tmp[i] += 32;
	}
	if (tmp[i])
		return (-1);
	return (checking_cmd_for_tocken(cmd, tmp, path));
}

static	void	init_cmd(t_commands *cmd, t_data *data)
{
	cmd->cmd = cmd->lst->content;
	cmd->invalid = checking_cmd(cmd, data->envp[data->path]);
	cmd->num_cmd = cmd->invalid;
}

void			init(t_commands **cmd, t_data *data)
{
	if (!(*cmd)->lst)
		return;
	init_cmd(*cmd, data);
	init_arg(*cmd);
}
