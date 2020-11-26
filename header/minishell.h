/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:48:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/26 14:57:16 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include "../libft/header/libft.h"

# define MALLOC_1 "Error : Malloc fail (init_struct_commands)"
# define MALLOC_2 "Error : Malloc fail (ft_command_line)"
# define MALLOC_3 "Error : Malloc fail (ft_devider)"
# define MALLOC_4 "Error : Malloc fail (ft_parse_mini_line)"
# define MALLOC_5 "Error : Malloc fail (ft_cd)"
# define MALLOC_6 "Error : Malloc fail (ft_join_all_args)"
# define MALLOC_7 "Error : Malloc fail (init_cmd)"
# define MALLOC_8 "Error : Malloc fail (init_arg)"
# define MALLOC_9 "Error : Malloc fail (create_env_v)"
# define MALLOC_10 "Error : Malloc fail (copy_double_array)"
# define MALLOC_11 "Error : Malloc fail (change_var)"
# define MALLOC_12 "Error : Malloc fail (ft_export)"
# define GNL_1 "Error : GNL fail (read_cmd)"
# define CMD_NO_FOUND "minishell: command not found: "
# define PWD_GETCWD "Error : too many characters in the path (getcwd)"
# define PWD_MANY_ARGS "pwd: too many arguments"
# define CD_STR_NOT "cd: string not in pwd: "
# define CD_MANY_ARGS "cd: too many arguments"
# define CD_NO_SUCH_F_D "cd: no such file or directory: "

typedef struct			s_data
{
	int					fd_0;
	int					fd_1;
	char				**envp;
	int					home_dir;
	int					current_pwd;
	int					old_pwd;
	int					env_var;
	int					path;
	int					count_str;
	char				*error_string;
}						t_data;

typedef struct			s_commands
{
	char				*cmd;
	int					num_cmd;
	char				*cmd_dir;
	int					count_args;
	//int					dit_find;
	int					type_redir;
	int					invalid;
	struct s_list		*lst;
	struct s_commands	*redir;
	struct s_commands	*pipe;
	struct s_commands	*previous;
	struct s_commands	*next;
}						t_commands;

int				main(int argc, char **argv, char **environ);
void			create_env(t_data *data, char **envp);
void			print_promt_string(void);
t_data			*init_struct_data(void);
void			signal_handler(int num);
void			read_cmd(t_data *data, char **line);
void			error_output(t_commands *cmd, t_data *data, char *str);
int				program_exit(t_commands *cmd, t_data *data, int num);
void			error_case(char *str1, char *str2, char *str3);

#endif
