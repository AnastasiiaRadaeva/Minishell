/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:39:16 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/03 21:18:07 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <string.h>
# include "minishell.h"

/*
** commands executor
** parametrs input:	syntax_tree - NULL or not
**						   data - not NULL
*/
void	executor(t_commands *syntax_tree, t_data *data);
void	execute_cmd_line(t_commands *cmd, t_data *data);
void	selection_cmd(t_commands *cmd, t_data *data,
								t_commands *redirect, t_commands *pip);

/*
** The function shows the current directory.
** Returns a string with the directory.
** Refine the function output.
** If an error occurs, the function prints the error string and calls error_output.
*/
void	ft_pwd(t_commands *cmd, t_data *all);

/*
** The function returns a one-dimensional array with all environment variables.
** If an error occurs, the function prints the error string and calls error_output.
** You need to think about how to output this error, I think that there is no need for exit.
*/
void	ft_env(t_commands *cmd, t_data *all);
int		redirects(t_commands *redir);

/*
** The function changes the working directory and in accordance with this change of variables
** environments.
** If an error occurs, the function prints the error string and calls error_output.
** You need to think about how to output this error, because you don't need exit, as
** I understand.
*/
void	ft_cd(t_commands **cmd, t_data *all);

/*
** The function returns the submitted arguments separated by a space.
** If there is no-t flag, the function adds \t at the end of the string.
** Returns the required string.
** If an error occurs, the function prints the error string and calls error_output.
** You need to think about how to output this error, I think that exit is needed here.
** By this time, all $ should have been processed.
** The function must be sold ready-made arguments.
*/
void	ft_echo(t_commands *cmd);

/*
** The function returns the submitted arguments separated by a space.
** If there is no-t flag, the function adds \t at the end of the string.
**  Returns the required string.
** If an error occurs, the function prints the error string and calls error_output.
** You need to think about how to output this error, I think that exit is needed here.
** By this time, all $ should have been processed.
** The function must be sold ready-made arguments.
*/

void	ft_export(t_commands **cmd, t_data **all, int index);
void	ft_check_cmd_in_path(t_commands **cmd, t_data **data);
void	ft_unset(t_commands **cmd, t_data **all);
int		check_syntax_error(t_commands *cmd);

#endif
