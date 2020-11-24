/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:12:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/23 18:39:32 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*Функция показывает текущую директорию. 
*Возвращает строку с директорией.
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*/

#include "../../header/minishell.h"

void	error_output(t_commands *cmd, char *str);

char	*ft_pwd(t_commands *cmd, t_data *all)
{
	if (!(all->envp[all->current_pwd]))
		error_output(cmd, PWD_GETCWD); // ошибку getcwd переписать 
	return (all->envp[all->current_pwd] + 4);
}