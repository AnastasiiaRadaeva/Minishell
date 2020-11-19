/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:51:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 21:52:30 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree_node		*cmd_line_1()
{
	t_astree_node	*job_node;
	t_astree_node	*cmd_line_node;
	t_astree_node	*result;

	if (!(job_node = job()))
		return (NULL);
	if (!term(CHAR_SEMICOLON, NULL))
	{
		astree_node_delete(job_node);
		return (NULL);
	}
	if (!(cmd_line_node = cmd_line()))
	{
		astree_node_delete(job_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_SEQ);
	astree_attach_binary_branch(result, job_node, cmd_line_node);
	return (result);
}

t_astree_node		*cmd_line_2()
{
	t_astree_node	*job_node;
	t_astree_node	*result;

	if (!(job_node = job()))
		return (NULL);
	if (!term(CHAR_SEMICOLON, NULL))
	{
		astree_node_delete(job_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_SEQ);
	astree_attach_binary_branch(result, job_node, NULL);
}

t_astree_node		*cmd_line_3()
{
	t_astree_node	*job_node;
	t_astree_node	*cmd_line_node;
	t_astree_node	*result;

	if (!(job_node = job()))
		return (NULL);
	if (!term(CHAR_AMPERSAND, NULL))
	{
		astree_node_delete(job_node);
		return (NULL);
	}
	if (!(cmd_line_node = cmd_line()))
	{
		astree_node_delete(job_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_BCKGRND);
	astree_attach_binary_branch(result, job_node, cmd_line_node);
}

t_astree_node		*cmd_line_4()
{
	t_astree_node	*job_node;
	t_astree_node	*result;

	if (!(job_node = job()))
		return (NULL);
	if (!term(CHAR_AMPERSAND, NULL))
	{
		astree_node_delete(job_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_type(result, NODE_BCKGRND);
	astree_attach_binary_branch(result, job_node, NULL);
}
