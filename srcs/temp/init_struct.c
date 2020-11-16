/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/13 15:20:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*init_struct_data(void)
{
	t_data *new_struct;

	if (!(new_struct = (t_data *)ft_calloc(sizeof(t_data), 1)))
		error_output(NULL, NULL);
	return (new_struct);
}

t_commands	*init_struct_commands(void)
{
	t_commands *new_tree;

	if (!(new_tree = (t_commands *)ft_calloc(sizeof(t_commands), 1)))
		error_output(new_tree, MALLOC_1);
	return (new_tree);
}
