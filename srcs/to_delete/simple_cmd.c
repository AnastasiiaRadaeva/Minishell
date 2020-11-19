/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:37:28 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 22:10:03 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree_node		*simple_cmd()
{
	t_tok			*save;
	
	save = curtok;
	return (simpl_cmd_1());
}

t_astree_node		*simpl_cmd_1()
{
	t_astree_node	*token_list_node;
	t_astree_node	*result;
	char			*pathname;

	if (!term(TOKEN, &pathname))
		return (NULL);
	token_list_node = token_list();
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_CMDPATH);
    astree_node_set_data(result, pathname);
	astree_attach_binary_branch(result, NULL, token_list_node);
	return (result);
}
