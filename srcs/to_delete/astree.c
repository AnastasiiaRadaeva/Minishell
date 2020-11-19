/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:14:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 21:24:43 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"

void	astree_attach_binary_branch(t_astree_node *root ,
									t_astree_node *leftNode,
									t_astree_node *rightNode)
{
	if (root)
	{
		root->left = leftNode;
		root->right = rightNode;
	}
		
}
void astree_node_set_type(t_astree_node *node, t_node_type nodetype)
{
	if (node)
		node->type = nodetype;
}

void astree_node_set_data(t_astree_node *node, char *data)
{
	if (node && data)
	{
		node->szData = data;
		node->type |= NODE_DATA;
	}
}

void astree_node_delete(t_astree_node *node)
{
	if (!node)
		return;
	if (node->type & NODE_DATA)
		free(node->szData);
	astree_node_delete(node->left);
	astree_node_delete(node->right);
	free(node);
}