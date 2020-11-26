/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/26 15:40:02 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int delete_lst(t_commands **cmd, t_list **lst_for_del, int num_of_lst, int error)
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (error == 1)
		error_case("minishell: export: `", (*lst_for_del)->content, "': not a valid identifier\n");
	// write(1, "Hello\n", 6);
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

static	int	find_char(char *str, char symb)
{
	int	i;

	i = 0;
	while (str[i] != symb)
		i++;
	return (i);
}

static void	change_var(t_data **all, t_commands **cmd)
{
	t_list	*tmp_lst;
	char 	**new_env;
	int 	index;
	int		num_of_lst;
	int		error;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		error = 0;
		index = 0;
		while ((*all)->envp[index])
		{
			int i = find_char((*all)->envp[index],'=');
			if (ft_strncmp((char *)tmp_lst->content, (*all)->envp[index], i + 1) == 0)
			{
				new_env = (*all)->envp;
				if (!((*all)->envp = (char **)malloc(sizeof(char *) * (*all)->count_str + 1)))
					error_output(*cmd, *all, "error: malloc (change_var)");
				i = 0;
				while (i < index)
				{
					(*all)->envp[i] = new_env[i];
					i++;
				}
				if (!((*all)->envp[i] = ft_strdup((char *)tmp_lst->content)))
					error_output(*cmd, *all, "error: malloc (change_var)");
				i++;
				free(new_env[i - 1]);
				while (new_env[i])
				{
					(*all)->envp[i] = new_env[i];
					i++;
				}
				(*all)->envp[i] = NULL;
				free(new_env);
				error = delete_lst(cmd, &tmp_lst, num_of_lst, 0);
				break;
			}
			index++;
		}
		if (error == 0)
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

static void	check_args_for_validity(t_commands **cmd)
/*Функция проверяет:
*Синтаксис (есть =, нет пробелов, 1-ый символ _ или буква, остальные символы _, цифра или буква).
*Меняет количество аргументов.
*Переставляет указатель на текущий лист.
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
			while (((char*)tmp_lst->content)[index] != '=' && ((char*)tmp_lst->content)[index] != '\0')
			{
				if (((char*)tmp_lst->content)[index] != '_' && ft_isalpha(((char*)tmp_lst->content)[index]) != 1 \
					&& ft_isalnum(((char*)tmp_lst->content)[index]) != 1)
				{
					error = delete_lst(cmd, &tmp_lst, num_of_lst, 1);
					break;
				}
				index++;
			}
			if (error == 0 && tmp_lst && ((char*)tmp_lst->content)[index] == '\0')
				error = delete_lst(cmd, &tmp_lst, num_of_lst, 0);
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

/*
** Функция добавляет переменную в конец (так как нам нужно будет все равно их тасовать)
*/

void	ft_export(t_commands **cmd, t_data **all)
{
	char	**temp_env;
	int		index;
	t_list	*temp_list;

	index = -1;
	check_args_for_validity(cmd);
	change_var(all, cmd);//Меняет переменную окружения, если она уже существует
	//и удаляет этот аргумент + меняет число аргкментов
	if ((*cmd)->lst)
	{
		(*all)->count_str += (*cmd)->count_args;
		temp_list = (*cmd)->lst;
		temp_env = (*all)->envp;
		if (!((*all)->envp = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
			error_output(*cmd, *all, MALLOC_12);


		while (temp_env[++index])
			(*all)->envp[index] = temp_env[index];
		while (index < (*all)->count_str)
		{
			(*all)->envp[index] = temp_list->content;
			temp_list = temp_list->next;
			index++;
		}
		(*all)->envp[index] = NULL;
		free(temp_env);
		
		
		// while (++index < (*all)->env_var)
		// 	(*all)->envp[index] = temp_env[index];
		// while (index < (*all)->count_str - 1)
		// {
		// 	(*all)->envp[index] = temp_list->content;
		// 	temp_list = temp_list->next;
		// 	index++;
		// }
		// (*all)->envp[index] = temp_env[(*all)->env_var];
		// (*all)->env_var += (*cmd)->count_args;
		// (*all)->envp[++index] = NULL;
		// free(temp_env);
	}
}