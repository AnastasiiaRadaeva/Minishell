/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/08 11:01:22 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_arg(t_list **tmp_lst, int *error, t_commands **cmd,\
													int *num_of_lst)
{
	int		index;

	index = 0;
	while (((char*)(*tmp_lst)->content)[++index] != '=' && \
		((char*)(*tmp_lst)->content)[index] != '\0')
	{
		if (((char*)(*tmp_lst)->content)[index] != '_' && \
			ft_isalpha(((char*)(*tmp_lst)->content)[index]) != 1 \
			&& ft_isalnum(((char*)(*tmp_lst)->content)[index]) != 1)
		{
			*error = delete_lst(cmd, tmp_lst, *num_of_lst, 1);
			return (1);
		}
	}
	if (*error == 0 && (*tmp_lst) && \
		((char*)(*tmp_lst)->content)[index] == '\0')
		*error = delete_lst(cmd, tmp_lst, *num_of_lst, 0);
	return (0);
}

static void	check_args_for_validity(t_commands **cmd)
{
	t_list	*tmp_lst;
	int		num_of_lst;
	int		error;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		error = 0;
		if ((((char*)tmp_lst->content)[0]) == '_' || \
				ft_isalpha(((char*)tmp_lst->content)[0]) == 1)
		{
			if (check_arg(&tmp_lst, &error, cmd, &num_of_lst) == 1)
				break ;
		}
		else
			error = delete_lst(cmd, &tmp_lst, num_of_lst, 1);
		if (error == 0)
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

static void	add_args(char **temp_env, t_data **all, t_commands **cmd)
{
	int		index;
	t_list	*temp_list;

	index = -1;
	while (temp_env[++index])
		(*all)->envp[index] = temp_env[index];
	temp_list = (*cmd)->lst;
	while (index < (*all)->count_str)
	{
		(*all)->envp[index++] = ft_strdup(temp_list->content);
		temp_list = temp_list->next;
	}
	(*all)->envp[index] = NULL;
}

void		ft_export(t_commands **cmd, t_data **all)
{
	char	**temp_env;
	int		index;

	index = -1;
	if ((*cmd)->lst)
	{
		check_args_for_validity(cmd);
		while (++index < (*cmd)->count_args)
			change_var(all, cmd, 0);
		(*all)->count_str += (*cmd)->count_args;
		temp_env = (*all)->envp;
		if (!((*all)->envp = (char **)malloc(sizeof(char *) * \
								((*all)->count_str + 1))))
			error_output(*cmd, *all, MALLOC_12);
		add_args(temp_env, all, cmd);
		free(temp_env);
	}
	else
		empty_export(all, cmd);
}
