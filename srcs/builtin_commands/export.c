/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcustard <kcustard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/22 16:25:49 by kcustard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*Функция выдает поданные аргументы через пробел. 
*Если нет флага -n, функция добавляет \n на конце строкию
*Возвращает требуемую строку.
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*Нужно подумать, как выводить эту ошибку, думаю, что тут нужен exit.
*К этому моменту все $ уже должны быть обработаны.
*В функцию должны подаваться уже готовые аргументы.
*/

#include "../../header/minishell.h"

void	error_output(t_commands *cmd, char *str);

void	check_args_for_validity(t_dats **all, t_commands **cmd)
/*Функция проверяет:
*Правильный синтаксис - нет пробелов, это буква.
*Если аргумент неверный, то нужно вывести сообщение об ошибке (возможно, 
*о всех ошибках)
*/ 
{

}

void	ft_export(t_commands **cmd, t_data **all)
{
	char	**temp_env;
	int		index;
	t_list	*temp_list;

	index = -1;
	temp_list = (*cmd)->lst;
	check_args_for_validity(all, cmd); //функция должна проверить на валидность аргументы и перезаписать их нужным образом
	change_var(all, cmd);//Меняет переменную окружения, если она уже существует
	//и удаляет этот аргумент + меняет число аргкментов
	(*all)->count_str += (*cmd)->count_args;
	temp_env = (*all)->envp;
	if (!((*all)->envp = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
		error_output(*cmd, MALLOC_12);
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