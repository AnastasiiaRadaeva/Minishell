/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcustard <kcustard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:12:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/20 17:25:41 by kcustard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*Функция показывает текущую директорию. 
*Возвращает строку с директорией.
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*Нужно подумать, как выводить эту ошибку, потому что тут не нужен exit, как 
*я понимаю.
*/

#include "../../header/minishell.h"

void	error_output(t_commands *cmd, char *str);

char	*ft_pwd(t_commands *cmd, t_data *all)
{
	if (cmd->count_args != 0)
		error_output(cmd, PWD_MANY_ARGS);
	if (!(all->envp[all->current_pwd]))
		error_output(cmd, PWD_GETCWD); // ошибку getcwd переписать 
	return (all->envp[all->current_pwd] + 4);
}