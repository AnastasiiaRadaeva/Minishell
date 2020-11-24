/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_enviroment_variable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:33:33 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/19 16:57:31 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**copy_double_array(char **origin, t_commands *cmd)
{
	char	**duplicate;
	int		num_of_str;
	int		index;

	num_of_str = 0;
	index = 0;
	while (origin[num_of_str])
		num_of_str++;
	if (!(duplicate = (char **)malloc(sizeof(char *) * (num_of_str + 1))))
		error_output(cmd, MALLOC_10);
	duplicate[num_of_str] = NULL;
	while (index < num_of_str)
	{
		if (!(duplicate[index] = ft_strdup(origin[index])))
			error_output(cmd, MALLOC_10);
		index++;
	}
	return (duplicate);
}

static void	data_filling(t_data **all, t_commands *cmd)
{
	int		index;

	index = 0;
	while ((*all)->envp[index])
	{
		if (ft_strncmp((*all)->envp[index], "HOME=", 5) == 0)
			(*all)->home_dir = index;
		if (ft_strncmp((*all)->envp[index], "PWD=", 4) == 0)
			(*all)->current_pwd = index;
		if (ft_strncmp((*all)->envp[index], "OLDPWD=", 7) == 0)
			(*all)->old_pwd = index;
		if (ft_strncmp((*all)->envp[index], "_=", 2) == 0)
			(*all)->env_var = index;
		index++;
	}
	(*all)->count_str = index;
}

void	create_env_v(t_data **all, char **envp_baze, t_commands *cmd)
{
	if (!((*all) = (t_data *)malloc(sizeof(t_data))))
		error_output(cmd, MALLOC_9);
	(*all)->envp = NULL;
	(*all)->home_dir = -1;
	(*all)->current_pwd = -1;
	(*all)->old_pwd = -1;
	(*all)->env_var = -1;
	(*all)->envp = copy_double_array(envp_baze, cmd);
	(*all)->count_str = -1;
	(*all)->error_string = NULL;
	data_filling(all, cmd);
}
