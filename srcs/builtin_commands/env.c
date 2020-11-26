/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:20:39 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/26 15:06:48 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char	*ft_env(t_commands *cmd, t_data *all)
void	ft_env(t_commands *cmd, t_data *all)
{
	//int		len;
	int		i;
	char	*string;
	char	*temp_str;

	i = 3;
	if (cmd->count_args > 0)
		error_case("env: ", cmd->lst->content, ": No such file or directory\n");
	else
	{
	/*
	len = ft_strlen(all->envp[all->env_var]);
	while (--i >= 0 && --len >= 0)
		all->envp[all->env_var][len] = cmd->cmd[i];
	*сначала нужно разобраться с тем, как отображается эта строка в 
	*bash и понять, где она там находится, нужно ли вообще её менять 
	*/
	if (!(string = ft_strdup("")))
		error_output(cmd,  all, "malloc: ft_env");
	i = 0;
	while (all->envp[i])
	{
		temp_str = string;
		if (!(string = ft_strjoin(string, all->envp[i])))
			error_output(cmd, all, "malloc: ft_env");
		free(temp_str);
		temp_str = string;
		if (!(string = all->envp[++i] ? ft_strjoin(string, "\n") : string))
			error_output(cmd, all, "malloc: ft_env");
		if (ft_strcmp(temp_str, string) != 0)
			free(temp_str);
	}
	// return (string);
	ft_putendl(string);
	}
}
