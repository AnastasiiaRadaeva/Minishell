/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:59:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 19:00:11 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_commands		*init_struct_commands(t_commands *cmd, t_data *data)
{
	t_commands 	*new_tree;

	if (!(new_tree = (t_commands *)ft_calloc(sizeof(t_commands), 1)))
		error_output(cmd, data, MALLOC_1);
	return (new_tree);
}
