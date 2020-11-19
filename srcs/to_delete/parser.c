/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:51:18 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/19 10:47:55 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astree.h"
#include "parser.h"
#include "lexer.h"


t_astree_node		*cmd_line()
{
	t_tok			*save;
	t_astree_node	*node;

	save = curtok;
	if ((curtok = save, node = cmd_line_1()))
		return (node);
	if ((curtok = save, node = cmd_line_2()))
		return (node);
	if ((curtok = save, node = cmd_line_3()))
		return (node);
	if ((curtok = save, node = cmd_line_4()))
		return (node);
	if ((curtok = save, node = cmd_line_5()))
		return (node);
	return (NULL);
}

int		parse(t_lexer *lexbuf, t_astree_node **syntax_tree)
{
	if (lexbuf->ntoks == 0)
		return (-1);
	curtok = lexbuf->llisttok;
	*syntax_tree = cmd_line();
	if ((curtok) && (curtok->type))
	{
		ft_putstr("Syntax Error near: ");
		ft_putstr(curtok->data);
		return (-1);
	}
	return (0);
}