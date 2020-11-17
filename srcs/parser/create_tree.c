/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/17 16:42:26 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_commands		*create_tree(t_data *data, char *line)
{
	char		*p;
	t_commands 	*cmd;
	t_commands	*tmp;

	cmd = NULL;
	p = line;
	cmd = init_struct_commands(cmd, data);
	tmp = cmd;
	while (*p)
	{
		data_collection(tmp, data, &p);
		add_node(&tmp, data, &p);
	}
	return (cmd);
}

