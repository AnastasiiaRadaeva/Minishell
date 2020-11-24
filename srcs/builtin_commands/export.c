/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/24 16:46:36 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_args_for_validity(t_data **all, t_commands **cmd)
/*Функция проверяет:
*Правильный синтаксис - нет пробелов, это буква.
*Если аргумент неверный, то нужно вывести сообщение об ошибке (возможно, 
*о всех ошибках)
*/ 
{
	t_list	*tmp_lst;

	tmp_lst = (*cmd)->lst;
	while (tmp_lst)
	{
		if (tmp_lst->content[0] != '_' && ft_isalpha(tmp_lst->content[0]) != 1)
		{
			if (tmp_lst->content[] != '_' && ft_isalpha(tmp_lst->content[0]) != 1)
		{
			ft_putstr("export: '");
			ft_putstr(tmp_lst->content);
			ft_putstr("': not a valid identifier\n");
		}
			ft_putstr("export: '");
			ft_putstr(tmp_lst->content);
			ft_putstr("': not a valid identifier\n");
		}

		tmp_lst = tmp_lst->next;
	}
}

void	ft_export(t_commands **cmd, t_data **all)
{
	char	**temp_env;
	int		index;
	t_list	*temp_list;

	index = -1;
	temp_list = (*cmd)->lst;
	// check_args_for_validity(all, cmd); //функция должна проверить на валидность аргументы и перезаписать их нужным образом
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