/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/04 15:42:14 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/header/libft.h"
#include "program_exit.h"
#include "signal.h"

typedef struct			s_commands
{
	char				*cmd;
	char				*cmd_dir;
	char				**arg;
	int					dit_find;
	int					type_redir;
	int					invalid;
	struct s_commands	*redir;
	struct s_commands	*pipe;
	struct s_commands	*next;
}						t_commands;

int				main(int argc, char **argv, char **environ);
// 
/*
*	promt string
*/
void			print_promt_string(void);

/*
*	initialization of structures
*/
void			init_struct_commands(t_commands *cmd);

/*
*	SIGNAL
*/
void			signal_handler(int num);
void			read_cmd(t_commands *cmd ,char **line);

t_commands		*creat_list(t_commands *cmd, char *line);

#endif