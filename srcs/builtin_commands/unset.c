/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:28:40 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/04 18:22:10 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_copy(t_data **all, t_list *tmp_lst)
{
	size_t	index;
	size_t	i;
	int		arg;

	index = 0;
	arg = 0;
	while ((*all)->envp[index])
	{
		i = 0;
		while ((*all)->envp[index][i] != '=')
			i++;
		if (ft_strncmp((char *)tmp_lst->content, (*all)->envp[index], i) == 0\
								&& i == ft_strlen((char *)tmp_lst->content))
			arg = 1;
		index++;
	}
	return (arg);
}

static void	delete_not_found_envp(t_data **all, t_commands **cmd)
{
	t_list	*tmp_lst;
	int		num_of_lst;
	int		arg;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		arg = find_copy(all, tmp_lst);
		if (arg == 0)
			del_lst(cmd, &tmp_lst, num_of_lst, 0);
		else
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

static int	check_arg(t_list **tmp_lst, t_commands **cmd, int *num_of_lst)
{
	int index;
	int	error;

	index = 1;
	error = 0;
	while (((char*)(*tmp_lst)->content)[index] != '\0')
	{
		if (((char*)(*tmp_lst)->content)[index] != '_' && \
			ft_isalpha(((char*)(*tmp_lst)->content)[index]) != 1 \
			&& ft_isalnum(((char*)(*tmp_lst)->content)[index]) != 1)
		{
			error = del_lst(cmd, tmp_lst, *num_of_lst, 1);
			break ;
		}
		index++;
	}
	return (error);
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
			error = check_arg(&tmp_lst, cmd, &num_of_lst);
		else
			error = del_lst(cmd, &tmp_lst, num_of_lst, 1);
		if (error == 0)
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

void		ft_unset(t_commands **cmd, t_data **all)
{
	check_args_for_validity(cmd);
	delete_not_found_envp(all, cmd);
	if ((*cmd)->lst)
		delete_right_env_variable(all, cmd);
}
