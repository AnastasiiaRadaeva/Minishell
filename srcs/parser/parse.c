/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:19:04 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/19 19:44:14 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			init_arg(t_commands *cmd)
{
	t_list			*tmp;
	
	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;
}

void			add_lst_to_node(t_commands **syntax_tree, char *data)
{
	t_list		*lst;

	if (!(lst = ft_lstnew(data)))
		error_output(NULL, NULL, NULL);
	ft_lstadd_back(&(*syntax_tree)->lst, lst);
}

void			init(t_commands **cmd)
{
	if (!(*cmd)->lst)
		return;
	init_cmd(*cmd);
	init_arg(*cmd);
}

void			add_nodes(t_commands **cmd, t_lexer *lexerbuf, t_data *data)
{
	t_lexer		*tmp;

	tmp = lexerbuf;
	if (tmp->llisttok->type == CHAR_GREATER || tmp->llisttok->type == CHAR_LESSER)
	{	
		init(cmd);
		(*cmd)->redir = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->redir;
	}
	else if (tmp->llisttok->type == CHAR_SEMICOLON)
	{
		init(cmd);
		(*cmd)->next = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->next;
	}
	else if (tmp->llisttok->type == CHAR_PIPE)
	{
		init(cmd);
		(*cmd)->pipe = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->pipe;
	}
	else
		add_lst_to_node(cmd, tmp->llisttok->data);
}

t_commands		*parse(t_data *data, t_lexer *lexerbuf)
{
	t_commands	*syntax_tree;
	t_commands	*tmp;

	syntax_tree = NULL;
	syntax_tree = init_struct_commands(syntax_tree, data);
	tmp = syntax_tree;
	while (lexerbuf->llisttok)
	{
		add_nodes(&tmp, lexerbuf, data);
		lexerbuf->llisttok = lexerbuf->llisttok->next;
	}
	if (!syntax_tree->next && !syntax_tree->redir && !syntax_tree->pipe)
		init(&syntax_tree);
	if (!tmp->next && !tmp->redir && !tmp->pipe && syntax_tree != tmp)
		init(&tmp);
	return (syntax_tree);	
}