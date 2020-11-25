/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:28:40 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/25 19:52:26 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int delete_lst(t_commands **cmd, t_list **lst_for_del, int num_of_lst, int error)
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (error == 1)
	{
		ft_putstr("minishell: unset: `");
		ft_putstr((*lst_for_del)->content);
		ft_putstr("': not a valid identifier\n");
	}
	tmp_lst = (*lst_for_del);
	new_lst = (*cmd)->lst;
	error = 0;
	if (num_of_lst == 0)
	{
		(*lst_for_del) = new_lst->next;
		(*cmd)->lst = new_lst->next;
	}
	else
		while (new_lst)
		{
			if (error == num_of_lst - 1)
			{
				new_lst->next = (*lst_for_del)->next;
				(*lst_for_del) = new_lst->next;
			}
			new_lst = new_lst->next;
			error++;
		}
	(*cmd)->count_args--;
	free(tmp_lst);
	return (1);
}

static void	delete_not_found_envp(t_data **all, t_commands **cmd)
{
	t_list	*tmp_lst;
	size_t	index;
	size_t	i;
	int		num_of_lst;
	int		arg;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		index = 0;
		arg = 0;
		while ((*all)->envp[index])
		{
			i = 0;
			while ((*all)->envp[index][i] != '=')
				i++;
			if (ft_strncmp((char *)tmp_lst->content, (*all)->envp[index], i) == 0 && i == ft_strlen((char *)tmp_lst->content))
				arg = 1;
			index++;
		}
		if (arg == 0)
			delete_lst(cmd, &tmp_lst, num_of_lst, 0);
		else
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

static void	check_args_for_validity(t_commands **cmd)
/*Функция проверяет:
*Синтаксис (1-ый символ _ или буква, остальные символы _, цифра или буква).
*Меняет количество аргументов.
*/ 
{
	t_list	*tmp_lst;
	int		index;
	int		num_of_lst;
	int		error;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		error = 0;
		if ((((char*)tmp_lst->content)[0]) == '_' || ft_isalpha(((char*)tmp_lst->content)[0]) == 1)
		{
			index = 1;
			while (((char*)tmp_lst->content)[index] != '\0')
			{
				if (((char*)tmp_lst->content)[index] != '_' && ft_isalpha(((char*)tmp_lst->content)[index]) != 1 \
					&& ft_isalnum(((char*)tmp_lst->content)[index]) != 1)
				{
					error = delete_lst(cmd, &tmp_lst, num_of_lst, 1);
					break;
				}
				index++;
			}
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

void	ft_unset(t_commands **cmd, t_data **all)
{
	char	**temp_env;
	size_t	index;
	t_list	*temp_list;
	size_t	i;

	index = -1;
	check_args_for_validity(cmd);
	delete_not_found_envp(all, cmd);
	if ((*cmd)->lst)
	{
		(*all)->count_str -= (*cmd)->count_args;
		temp_list = (*cmd)->lst;
		temp_env = (*all)->envp;
		if (!((*all)->envp = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
			error_output(*cmd, *all, MALLOC_12);
		while (temp_list)
		{
			index = 0;
			while ((*all)->envp[index])
			{
				i = 0;
				while ((*all)->envp[index][i] != '=')
					i++;
				if (ft_strncmp((char *)temp_list->content, (*all)->envp[index], i) == 0 && i == ft_strlen((char *)temp_list->content))
				{
					i = 0;
					while (i < index)
					{
						(*all)->envp[i] = temp_env[i];
						i++;
					}
					while (temp_env[i])
					{
						(*all)->envp[i] = temp_env[i + 1];
						i++;
					}
					free(temp_env);
					break;
				}
				index++;
			}
			temp_list = temp_list->next;
		}
	}
}
