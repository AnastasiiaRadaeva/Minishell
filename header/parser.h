/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:35:52 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/11 11:39:39 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "minishell.h"

void		create_list(t_commands *cmd, char **line, char **new_line);
char		*move_pointer(char *p1, char *p2);
int			checking_cmd_for_tocken(char *word);

#endif
