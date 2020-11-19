/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:32:46 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 22:07:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree_node		*token_list_2()
{
	return (NULL);
}

t_astree_node		*token_list_1()
{
	t_astree_node	*token_list_node;
	t_astree_node	*result;
	char			*arg;
	
	if (!term(TOKEN, &arg))
		return (NULL);
	token_list_node = token_list();
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_ARGUMENT);
	astree_node_set_data(result, arg);
	astree_attach_binary_branch(result, NULL, token_list_node);
	return (result);
}

t_astree_node		*token_list()
{
	t_tok			*save;
	t_astree_node	*node;

	save = curtok;
	if ((curtok = save, node = token_list_1()))
		return (node);
	if ((curtok = save, node = token_list_2()))
		return (node);
	return (NULL);
}
