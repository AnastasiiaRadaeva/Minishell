/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:22:15 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 14:13:18 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_with_status(t_commands **cmd)
{
	error_case("minishell: cd: ", (*cmd)->lst->content, \
							": No such file or directory\n");
	global_status = 1;
}

static void	change_var_for_cd(t_commands *cmd, t_data **all)
{
	char	*tmp;
	char	*tmp_2;
	char	*tmp_3;

	tmp = (*all)->envp[(*all)->old_pwd];
	if (!((*all)->envp[(*all)->old_pwd] = ft_strjoin("OLD", \
			(*all)->envp[(*all)->current_pwd])))
		error_output(cmd, *all, MALLOC_11);
	free(tmp);
	if (!(tmp_2 = (char *)malloc(sizeof(char) * 100)))
		error_output(cmd, *all, MALLOC_11);
	getcwd(tmp_2, 100);
	tmp = (*all)->envp[(*all)->current_pwd];
	tmp_3 = ft_strndup(tmp_2, ft_strlen(tmp_2));
	free(tmp_2);
	if (!((*all)->envp[(*all)->current_pwd] = ft_strjoin("PWD=", \
			tmp_3)))
		error_output(cmd, *all, MALLOC_11);
	free(tmp);
	free(tmp_3);
}

void		ft_cd(t_commands **cmd, t_data *all)
{
	char	*tmp_path;

	if ((*cmd)->count_args == 0)
	{
		if (!((*cmd)->lst = (t_list *)malloc(sizeof(t_list))))
			error_output(*cmd, all, MALLOC_5);
		((*cmd)->lst->content) = all->envp[all->home_dir] + 5;
		(*cmd)->lst->next = NULL;
	}
	if (((char*)(*cmd)->lst->content)[0] == '~')
	{
		if (!(tmp_path = ft_strjoin(all->envp[all->home_dir] + 5,
								(char *)(*cmd)->lst->content + 1)))
			error_output(*cmd, all, MALLOC_5);
		free((char *)((*cmd)->lst->content));
		((*cmd)->lst->content) = tmp_path;
	}
	if (chdir((char *)(*cmd)->lst->content) != 0)
		error_with_status(cmd);
	change_var_for_cd(*cmd, &all);
}
