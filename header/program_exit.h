/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_exit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:46:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/04 12:19:26 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_EXIT_H
# define PROGRAM_EXIT_H

#include "minishell.h"

# define MALLOC_1 "Error : Malloc fail (init_struct_commands)"
# define GNL_1 "Error : GNL fail (read_cmd)"

void	error_output(t_commands *cmd, char *str);
int		program_exit(t_commands *cmd, int num);

#endif