/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:15:10 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 11:19:25 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	size_t	find_char(char *str, char symb)
{
	size_t	i;

	i = 0;
	while (str[i] != symb)
		i++;
	return (i);
}

static void		del_arg(t_commands **cmd, char **temp_env, int *index)
{
	t_list	*temp_list;
	size_t	f;

	temp_list = (*cmd)->lst;
	while (temp_list && temp_env[*index])
	{
		f = find_char(temp_env[*index], '=');
		if (ft_strncmp((char *)temp_list->content, temp_env[*index], f) == 0\
							&& f == ft_strlen((char *)temp_list->content))
		{
			*index += 1;
			free(temp_env[*index - 1]);
			temp_list = (*cmd)->lst;
		}
		else
			temp_list = temp_list->next;
	}
}

void			delete_right_env_variable(t_data **all, t_commands **cmd)
{
	char	**temp_env;
	int		index;
	int		i;

	index = 0;
	i = 0;
	(*all)->count_str -= (*cmd)->count_args;
	temp_env = (*all)->envp;
	if (!((*all)->envp = (char **)malloc(sizeof(char *) * \
			((*all)->count_str + 1))))
		error_output(*cmd, *all, MALLOC_12);
	while (temp_env[index])
	{
		del_arg(cmd, temp_env, &index);
		if (temp_env[index])
		{
			(*all)->envp[i] = temp_env[index];
			i++;
			index++;
		}
	}
	(*all)->envp[i] = NULL;
	free(temp_env);
}
