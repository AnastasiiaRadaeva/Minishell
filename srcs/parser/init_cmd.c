/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:48:22 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/10 11:49:25 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "dirent.h"
#include <sys/types.h>

static int	check_full_path(t_commands *cmd, char *tmp, char *p)
{
	char	*rewrite;

	if (!access(tmp, F_OK))
	{
		rewrite = cmd->cmd;
		cmd->cmd_dir = ft_strndup(tmp, p - tmp);
		cmd->cmd = ft_strdup(p);
		free(rewrite);
		rewrite = NULL;
		return (0);
	}
	return (1);
}

static int	check(t_commands **cmd, char ***split_path, DIR **dir, int *i)
{
	int		j;
	char	*tmp_1;

	j = 0;
	tmp_1 = (*cmd)->cmd;
	(*cmd)->cmd = ft_strjoin("/", (*cmd)->cmd);
	free(tmp_1);
	(*cmd)->cmd_dir = ft_strdup((*split_path)[(*i)]);
	while ((*split_path)[j])
		ft_free_tmp((*split_path)[j++]);
	free((*split_path));
	free((*dir)->__dd_buf);
	free(*dir);
	*dir = NULL;
	return (0);
}

static int	check_cmd_in_path(t_commands *cmd, char *tmp,\
													char **split_path)
{
	DIR				*dir;
	struct dirent	*entry;
	int				i;
	char			*p;

	i = -1;
	if ((p = ft_strrchr(tmp, '/')))
	{
		ft_free_two_dimensional_arr(split_path);
		return (check_full_path(cmd, tmp, ++p));
	}
	while (split_path[++i])
	{
		dir = opendir(split_path[i]);
		while ((entry = readdir(dir)))
			if (!ft_strcmp(entry->d_name, tmp))
				return (check(&cmd, &split_path, &dir, &i));
		if (dir)
		{
			free(dir->__dd_buf);
			ft_free_tmp(dir);
		}
	}
	ft_free_two_dimensional_arr(split_path);
	return (1);
}

static int	checking_cmd_for_tocken(t_commands *cmd, char *tmp, char *path)
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
	else if (path && !check_cmd_in_path(cmd, tmp, ft_split(path + 5, ':')))
		return (CMD_IN_PATH);
	return (CMD_ERROR);
}

int			checking_cmd(t_commands *cmd, char *path)
{
	char		*tmp;
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
