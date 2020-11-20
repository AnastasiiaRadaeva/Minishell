/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:39:16 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 19:21:13 by anatashi         ###   ########.fr       */
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
void			give_pwd(t_commands *cmd, t_data *data);
int				redirects(t_commands *redir);

#endif
