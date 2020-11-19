/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:44:08 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 21:45:46 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree_node		*cmd_1()
{
	t_astree_node	*simple_cmd_node;
	t_astree_node	*result;
	char			*filname;
	
	if (!(simple_cmd_node = simple_cmd()))
		return (NULL);
	if (!term(CHAR_LESSER, NULL))
	{
		astree_node_delete(simple_cmd_node);
		return(NULL);
	}
	if (!term(TOKEN, &filname))
	{
		ft_free_tmp(filname);
		astree_node_delete(simple_cmd_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_REDIRECT_IN);
	astree_node_set_data(result, filname);
	astree_attach_binary_branch(result, NULL, simple_cmd_node);
	return (NULL);
}

t_astree_node		*cmd_2()
{
	t_astree_node	*simple_cmd_node;
	t_astree_node	*result;
	char			*filname;

	if (!(simple_cmd_node = simple_cmd()))
		return (NULL);
	if (!term(CHAR_GREATER, NULL))
	{
		astree_node_delete(simple_cmd_node);
		return (NULL);
	}
	if (!term(TOKEN, &filname))
	{
		ft_free_tmp(filname);
		astree_node_delete(simple_cmd_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_REDIRECT_OUT);
	astree_node_set_data(result, filname);
	astree_attach_binary_branch(result, NULL, simple_cmd_node);
	return (result);
}

t_astree_node		*cmd_3()
{
	return (simple_cmd());
}

t_astree_node		*cmd()
{
	t_tok			*save;
	t_astree_node	*node;

	save = curtok;
	if ((curtok = save, node = cmd_1()))
		return (node);
	if ((curtok = save, node = cmd_2()))
		return (node);
	if ((curtok = save, node = cmd_3()))
		return (node);
	return (NULL);
}