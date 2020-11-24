/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:39:16 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/24 12:59:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <string.h>
# include "minishell.h"

void			executor(t_commands *syntax_tree, t_data *data);
void			execute_cmd_line(t_commands *cmd, t_data *data);
void			selection_cmd(t_commands *cmd, t_data *data,
								t_commands *redirect, t_commands *pip);

/*
** Функция показывает текущую директорию. 
** Возвращает строку с директорией. 
** Уточнить вывод функции.
** В случае ошибки функция печатает строку ошибки и вызывает error_output.
*/
// char			*ft_pwd(t_commands *cmd, t_data *all);
void			ft_pwd(t_commands *cmd, t_data *all);

/*
*Функция возвращает одномерный массив со всеми переменными окружения.
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*Нужно подумать, как выводить эту ошибку, думаю, что тут не нужен exit.
*/
// char	*ft_env(t_commands *cmd, t_data *all)
void	ft_env(t_commands *cmd, t_data *all);
int				redirects(t_commands *redir);

/*
*Функция меняет рабочую директорию и в соответствии с этим меняет переменные 
*окружения. 
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*Нужно подумать, как выводить эту ошибку, потому что тут не нужен exit, как 
*я понимаю.
*/
void	ft_cd(t_commands **cmd, t_data *all);

#endif
