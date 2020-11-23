/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:19:04 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/23 12:08:49 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void 		_strip_quotes(char *content, size_t n, int j)
{
	size_t 	i;
	char	lastquote;
	char	c;

	i = -1;
	lastquote = 0;
	while (++i < n)
	{
		c = content[i];
		if ((c == '\'' || c == '\"') && lastquote == 0)
			lastquote = c;
		else if (c == lastquote)
			lastquote = 0;
		else
			content[j++] = c;
	}
	content[j] = 0;
}

static	void	add_lst_to_node(t_commands **syntax_tree, t_data *data,
								char *content, int type)
{
	t_list		*lst;
	// char		*tmp;
	(void)data;
	if (type == CHAR_QOUTE || type == CHAR_DQUOTE)
	{
		// tmp = content;
		_strip_quotes(content, ft_strlen(content), 0);
		// ft_free_tmp(tmp);
	}
	if (*content)
	{
		if (!(lst = ft_lstnew(content)))
			error_output(NULL, NULL, NULL);
		ft_lstadd_back(&(*syntax_tree)->lst, lst);
	}
}

static	void	add_nodes(t_commands **cmd, t_lexer *lexerbuf, t_data *data)
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
		add_lst_to_node(cmd, data, tmp->llisttok->data, tmp->llisttok->type);
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
