/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:47:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/18 21:47:52 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_astree_node		*job_1()
{
	t_astree_node	*cmd_node;
	t_astree_node	*job_node;
	t_astree_node	*result;

	if (!(cmd_node = cmd()))
		return (NULL);
	if (!term(CHAR_PIPE, NULL))
	{
		astree_node_delete(cmd_node);
		return (NULL);
	}
	if (!(job_node = job()))
	{
		astree_node_delete(cmd_node);
		return (NULL);
	}
	result = malloc(sizeof(*result));
	astree_node_set_data(result, NODE_PIPE);
	astree_attach_binary_branch(result, cmd_node, job_node);
	
}

t_astree_node		*job_2()
{
	return (CMD());
}

t_astree_node		*job()
{
	t_tok			*save;
	t_astree_node	*node;

	save = curtok;
	if ((curtok = save, node = job_1()))
		return (NULL);
	if ((curtok = save, node = job_2()))
		return (NULL);
	return (NULL);
}
