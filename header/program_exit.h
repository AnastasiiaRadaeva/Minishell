/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:46:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/17 16:09:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_EXIT_H
# define PROGRAM_EXIT_H

#include "minishell.h"

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

void	error_output(t_commands *cmd, t_data *data, char *str);
int		program_exit(t_commands *cmd, t_data *data, int num);

#endif
