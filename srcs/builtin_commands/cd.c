/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:22:15 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/24 14:36:19 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_var(t_commands *cmd, t_data **all)
{
	char	*tmp;
	char	*tmp_2;

	tmp = (*all)->envp[(*all)->old_pwd];
	if (!((*all)->envp[(*all)->old_pwd] = ft_strjoin("OLD", (*all)->envp[(*all)->current_pwd])))
		error_output(cmd, *all, MALLOC_11);
	free(tmp);
	if (!(tmp_2 = (char *)malloc(sizeof(char) * 100)))
		error_output(cmd, *all, MALLOC_11);
	getcwd(tmp_2, 100);
	tmp = (*all)->envp[(*all)->current_pwd];
	if (!((*all)->envp[(*all)->current_pwd] = ft_strjoin("PWD=", ft_strndup(tmp_2, ft_strlen(tmp_2)))))
		error_output(cmd, *all, MALLOC_11);
	free(tmp);
	free(tmp_2);
}

void	ft_cd(t_commands **cmd, t_data *all)
{
	char	*tmp_path;

	if ((*cmd)->count_args == 0)
	{
		if (!((*cmd)->lst = (t_list *)malloc(sizeof(t_list))))
				error_output(*cmd, all, MALLOC_11); //нужен маллок 14
		((*cmd)->lst->content) = all->envp[all->home_dir] + 5;
		(*cmd)->lst->next = NULL;
	}
	if ((*cmd)->count_args > 1)
	{
		ft_putstr("cd: ");
		ft_putstr((*cmd)->lst->content);
		ft_putstr(": No such file or directory\n");
	}
	if (((char*)(*cmd)->lst->content)[0] == '~')
	{
		if (!(tmp_path = ft_strjoin(all->envp[all->home_dir] + 5, (char *)(*cmd)->lst->content + 1)))
			error_output(*cmd,  all, MALLOC_5);
		free((char *)((*cmd)->lst->content));
		((*cmd)->lst->content) = tmp_path;
	}
	if (chdir((char *)(*cmd)->lst->content) != 0)
	{
		ft_putstr(CD_NO_SUCH_F_D);
		error_output(*cmd,  all, (*cmd)->lst->content);
	}
	change_var(*cmd, &all);
}
