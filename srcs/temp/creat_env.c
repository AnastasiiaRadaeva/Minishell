/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:37:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/02 14:17:54 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static	size_t	find_char(char *str, char symb)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != symb)
// 		i++;
// 	return (i);
// }

// static void	del_env_var(t_data **all, char *del)
// {
// 	char	**temp_env;
// 	int		index;
// 	int		i;

// 	index = -1;
// 	i = -1;
// 	temp_env = (*all)->envp;
// 	if (!((*all)->envp = (char **)malloc(sizeof(char *) * (*all)->count_str)))
// 		error_output(NULL, *all, MALLOC_12);
// 	while (temp_env[++index])
// 	{
// 		if (ft_strncmp(del, temp_env[index], find_char(temp_env[index],'='))\
// 				 == 0 && find_char(temp_env[index],'=') == ft_strlen(del) - 1)
// 		{
// 			index++;
// 			free(temp_env[index - 1]);
// 		}
// 		if (temp_env[index])
// 			(*all)->envp[++i] = temp_env[index];
// 	}
// 	(*all)->envp[i] = NULL;
// 	free(temp_env);
// }

static void	parse_env(t_data *data)
{
	int 	i;

	i = -1;
	while (data->envp[++i])
	{
		if (!ft_strncmp(data->envp[i], "PWD=", 4))
			data->current_pwd = i;
		else if (!ft_strncmp(data->envp[i], "HOME=", 5))
			data->home_dir = i;
		else if (!ft_strncmp(data->envp[i], "OLDPWD=", 7)) 
			data->old_pwd = i;
		else if (!ft_strncmp(data->envp[i], "PATH=", 5))
			data->path = i;
		if (ft_strncmp((data)->envp[i], "_=", 2) == 0)
			data->env_var = i;
	}
	data->count_str = i;
}

void		create_env(t_data *data, char **envp)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (envp[i])
		i++;
	if (!(data->envp = (char **)malloc(sizeof(char *) * (i + 1))))
		error_output(NULL, data, NULL);
	while (++j != i)
	{
		if (!(data->envp[j] = ft_strdup(envp[j])))
			error_output(NULL, data, NULL);
	}
	data->envp[j] = NULL;
	data->count_str = i;
	parse_env(data);
}