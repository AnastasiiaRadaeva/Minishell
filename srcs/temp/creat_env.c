/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:37:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/01 20:55:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	change_place(t_data **all, t_commands **cmd)
// {
// 	int		i;
// 	int		index;
// 	int		flag;
// 	char	**tmp;

// 	tmp = (*all)->envp;
// 	index = 0;
// 	i = 0;
// 	if (!((*all)->envp = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
// 		error_output(*cmd, *all, MALLOC_12);
// 	(*all)->envp[i] = tmp[index];
// 	while (tmp[++index])
// 	{
// 		if (ft_strcmp((*all)->envp[i], tmp[index]) < 0)
// 		{
// 			(*all)->envp[i] = tmp[index];
// 			(*all)->envp[++i] = tmp[index - 1];
// 		}
// 		else
// 		{
// 			(*all)->envp[i] = tmp[index];
// 		}
		
// 	}

// }

static	size_t	find_char(char *str, char symb)
{
	size_t	i;

	i = 0;
	while (str[i] != symb)
		i++;
	return (i);
}

static void	del_env_var(t_data **all, char *del)
{
	char	**temp_env;
	int		index;
	int		i;

	index = -1;
	i = -1;
	temp_env = (*all)->envp;
	(*all)->envp = (char **)malloc(sizeof(char *) * (*all)->count_str);
	while (temp_env[++index])
	{
		if (ft_strncmp(del, temp_env[index], find_char(temp_env[index],'='))\
				 == 0 && find_char(temp_env[index],'=') == ft_strlen(del) - 1)
		{
			index++;
			free(temp_env[index - 1]);
		}
		if (temp_env[index])
			(*all)->envp[++i] = temp_env[index];
	}
	(*all)->envp[i] = NULL;
	free(temp_env);
}

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
		data->envp[j] = ft_strdup(envp[j]);
	data->envp[j] = NULL;
	data->count_str = i;
	del_env_var(&data, "OLDPWD=");
	parse_env(data);
}