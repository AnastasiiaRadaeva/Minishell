/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/24 20:51:56 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void delete_lst(t_commands **cmd, t_list **lst_for_del, int *num_of_lst, int error)
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (error == 1)
	{
		ft_putstr("export: '");
		ft_putstr((*lst_for_del)->content);
		ft_putstr("': not a valid identifier\n");
	}
	write(1, "Hello\n", 6);
	tmp_lst = (*lst_for_del);
	new_lst = (*cmd)->lst;
	error = 0;
	if ((*num_of_lst) == 0)
		(*num_of_lst) = 1;
	while (new_lst)
	{
		if (error == (*num_of_lst) - 1)
		{
			(*lst_for_del) = new_lst;
			new_lst = new_lst->next;
		}
		if (new_lst)
			new_lst = new_lst->next;
		error++;
	}
	write(1, "Hello_1\n", 8);
	(*num_of_lst)--;
	(*cmd)->count_args--;
	free(tmp_lst);
}

static void	check_args_for_validity(t_commands **cmd)
/*Функция проверяет:
*Правильный синтаксис - нет пробелов, это буква.
*Если аргумент неверный, то нужно вывести сообщение об ошибке (возможно, 
*о всех ошибках)
*/ 
{
	t_list	*tmp_lst;
	int		index;
	int		num_of_lst;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		if ((((char*)tmp_lst->content)[0]) == '_' || ft_isalpha(((char*)tmp_lst->content)[0]) == 1)
		{
			index = 1;
			while (((char*)tmp_lst->content)[index] != '=' && ((char*)tmp_lst->content)[index] != '\0')
			{
				if (((char*)tmp_lst->content)[index] != '_' && ft_isalpha(((char*)tmp_lst->content)[index]) != 1 \
					&& ft_isalnum(((char*)tmp_lst->content)[index]) != 1)
				{
					delete_lst(cmd, &tmp_lst, &num_of_lst, 1);
					break;
				}
				index++;
			}
			if (((char*)tmp_lst->content)[index] == '\0')
				delete_lst(cmd, &tmp_lst, &num_of_lst, 0);
		}
		else
			delete_lst(cmd, &tmp_lst, &num_of_lst, 1);
		tmp_lst = tmp_lst->next;
		num_of_lst++;
	}
}

void	ft_export(t_commands **cmd, t_data **all)
{
	char	**temp_env;
	int		index;
	t_list	*temp_list;

	index = -1;
	temp_list = (*cmd)->lst;
	check_args_for_validity(cmd); //функция должна проверить на валидность аргументы и перезаписать их нужным образом
	// change_var(all, cmd);//Меняет переменную окружения, если она уже существует
	//и удаляет этот аргумент + меняет число аргкментов
	(*all)->count_str += (*cmd)->count_args;
	temp_env = (*all)->envp;
	if (!((*all)->envp = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
		error_output(*cmd, *all, MALLOC_12);
	while (++index < (*all)->env_var)
		(*all)->envp[index] = temp_env[index];
	while (index < (*all)->count_str - 1)
	{
		(*all)->envp[index] = temp_list->content;
		temp_list = temp_list->next;
		index++;
	}
	(*all)->envp[index] = temp_env[(*all)->env_var];
	(*all)->envp[++index] = NULL;
	free(temp_env);
}