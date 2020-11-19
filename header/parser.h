/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:35:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/19 17:00:19 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "minishell.h"
#include "lexer.h"


t_commands		*create_tree(t_data *data, char *line);

/*
**	collecting data about cmd
*/
void			data_collection(t_commands *cmd, t_data *data, char **line);

size_t			move_pointer(t_commands *cmd, t_data *data, char *p, char *line);
void 			init_cmd(t_commands *cmd);
void			add_node(t_commands **cmd, t_data *data, char **line);

t_commands		*parse(t_data *data, t_lexer *lexerbuf);

#endif
