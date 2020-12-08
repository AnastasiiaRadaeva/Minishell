/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:59:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/08 20:46:18 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_commands		*init_struct_commands(t_commands *cmd, t_data *data)
{
	t_commands	*new_tree;

	if (!(new_tree = (t_commands *)malloc(sizeof(t_commands))))
		error_output(cmd, data, MALLOC_1);
	new_tree->cmd = NULL;
	new_tree->cmd_dir = NULL;
	new_tree->count_args = 0;
	new_tree->invalid = 0;
	new_tree->lst = NULL;
	new_tree->next = NULL;
	new_tree->num_cmd = 0;
	new_tree->pipe = NULL;
	new_tree->previous = NULL;
	new_tree->redir = NULL;
	new_tree->type_redir = 0;
	return (new_tree);
}
