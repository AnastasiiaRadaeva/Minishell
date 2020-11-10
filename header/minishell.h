/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/10 16:56:25 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/header/libft.h"
#include "signal.h"
#include <unistd.h>

typedef struct			s_commands
{
	char				*cmd;
	char				*cmd_dir;
	char				**arg;
	int					count_args;
	//int					dit_find;
	int					type_redir;
	int					invalid;
	struct s_commands	*redir;
	struct s_commands	*pipe;
	struct s_commands	*next;
}						t_commands;

typedef struct			s_data
{
	char				**envp;
	int					home_dir;
	int					current_pwd;
	int					old_pwd;
	int					env_var;
}						t_data;

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



/*
*	print result
*/
void			print_result(t_commands *cmd, char *line);

#include "program_exit.h"
#include "parser.h"
#endif
