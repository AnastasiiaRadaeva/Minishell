/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/14 16:08:27 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/header/libft.h"
#include "signal.h"
// #include <unistd.h>

# define SEPARATORS "|;<>"
# define WHITESPACES " \t\n\v\f\r"
# define SPECSYMBOL " \\$\'\""
# define QUOTE " \\$\'\""
# define TMP "|;<>\'\""
// 
typedef struct			s_commands
{
	char				*cmd;
	unsigned int		num_cmd;
	char				*cmd_dir;
	int					count_args;
	//int					dit_find;
	int					type_redir;
	int					invalid;
	struct s_list		*lst;
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
t_commands		*init_struct_commands(void);
t_data			*init_struct_data(void);

/*
*	SIGNAL
*/
void			signal_handler(int num);
void			read_cmd(char **line);



/*
*	print result
*/
void			print_result(t_commands *cmd, char *line);

#include "program_exit.h"
#include "parser.h"
#include "tools.h"
#endif
