/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:35:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/16 16:34:17 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "minishell.h"

t_commands		*create_list(t_data *data, char *line);
void			data_collection(t_commands **cmd, t_data *data, char **line);
size_t			move_pointer(t_commands *cmd, t_data *data, char *p, char *line);
int				checking_cmd_for_tocken(char *word);
void			add_node(t_commands *cmd, t_data *data, char **line);
#endif
