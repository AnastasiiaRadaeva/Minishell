/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:28:40 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/26 17:06:18 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int delete_lst(t_commands **cmd, t_list **lst_for_del, int num_of_lst, int error)
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (error == 1)
		error_case("minishell: unset: `", (*lst_for_del)->content, "': not a valid identifier\n");
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

static	size_t	find_char(char *str, char symb)
{
	size_t	i;

	i = 0;
	while (str[i] != symb)
		i++;
	return (i);
}

static void	delete_right_env_variable(t_data **all, t_commands **cmd)
{
	t_list	*temp_list;
	char	**temp_env;
	int		index;
	int		i;

	index = 0;
	i = 0;
	(*all)->count_str -= (*cmd)->count_args;
	temp_env = (*all)->envp;
	if (!((*all)->envp = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
		error_output(*cmd, *all, MALLOC_12);
	while (temp_env[index])
	{
		temp_list = (*cmd)->lst;
		while (temp_list && temp_env[index])
		{
			size_t f = find_char(temp_env[index],'=');
			if (ft_strncmp((char *)temp_list->content, temp_env[index],	f) == 0 && \
			f == ft_strlen((char *)temp_list->content))
			{
				index++;
				free(temp_env[index - 1]);
				temp_list = (*cmd)->lst;
			}
			else
				temp_list = temp_list->next;
		}
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

void	ft_unset(t_commands **cmd, t_data **all)
{
	check_args_for_validity(cmd);
	delete_not_found_envp(all, cmd);
	if ((*cmd)->lst)
		delete_right_env_variable(all, cmd);
}
