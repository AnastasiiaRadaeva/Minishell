/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:43:29 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 21:15:35 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTREE_H
#define ASTREE_H

typedef enum 			s_node_type
{
    NODE_PIPE 			= (1 << 0),
    NODE_BCKGRND 		= (1 << 1),
    NODE_SEQ 			= (1 << 2),
    NODE_REDIRECT_IN 	= (1 << 3),
    NODE_REDIRECT_OUT 	= (1 << 4),
    NODE_CMDPATH		= (1 << 5),
    NODE_ARGUMENT		= (1 << 6),

    NODE_DATA 			= (1 << 7),
} 						t_node_type;

typedef struct 				s_astree_node
{
    int 					type;
    char 					*szData;
    struct s_astree_node	*left;
    struct s_astree_node	*right;

} 						t_astree_node;

#define NODETYPE(a) (a & (~NODE_DATA))	// get the type of the nodes

void	astree_attach_binary_branch(t_astree_node *root ,
									t_astree_node *leftNode,
									t_astree_node *rightNode);
void	astree_node_set_type(t_astree_node *node, t_node_type nodetype);
void	astree_node_set_data(t_astree_node *node, char *data);
void	astree_node_delete(t_astree_node *node);

#endif