/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:19:04 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/26 18:54:04 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				check_env(char	**envp, char *var, int size)
{
	int			i;
	int			j;
	int			recover_size;

	recover_size = size;
	i = -1;
	while (envp[++i])
	{
		j = 0;
		if (envp[i][j] == var[j])
		{
			size = recover_size;
			while (envp[i][j] == var[j] && size)
			{	
				if ((envp[i][j + 1] == '=' || envp[i][j + 1] == '\0') && size == 1)
					return (i);
				j++;
				size--;
			}
		}
	}
	return (0);
}


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


/*
** p 	- a pointer to the CHAR_DOLLAR
** rem	- the remainder of the string after $ content
*/
void			_if_type_dollar(t_data *data, char **content, char *rem)
{
	char		*p;
	int			i;
	int			num_env;

	i = 0;
	p = rem ? ft_strchr(rem, CHAR_DOLLAR) : ft_strchr(*content, CHAR_DOLLAR);
	if (p)
	{
		p++;
		i = (p[i] == '_' || ft_isalpha(p[i])) ? 1 : 0;
		if (i)
		{
			while (p[i] == '_' || ft_isalnum(p[i]))
				i++;
			if ((num_env = check_env(data->envp, p, i)))
			{
				p--;
				*p = '\0';
				rem = ft_strdup(p + i + 1);
				*content = ft_strjoin_gnl(content, data->envp[num_env] + i + 1);
				if (rem != '\0')
					_if_type_dollar(data, content, rem);
			}
			else
			{
				ft_free_tmp(*content);
				*content = ft_strdup("");
			}
			

		}
	}
}

static	void	add_lst_to_node(t_commands **syntax_tree, t_data *data,
								char *content, int type)
{
	t_list		*lst;
	
	(void)data;
	// if (type == CHAR_QOUTE || type == CHAR_DQUOTE)
	{	
		if (type == CHAR_DQUOTE)
			_if_type_dollar(data, &content, NULL);	
	_strip_quotes(content, ft_strlen(content), 0);
	}
	if (type == CHAR_DOLLAR)
		_if_type_dollar(data, &content, NULL);
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
	t_commands	*tmp_cmd;

	tmp = lexerbuf;
	tmp_cmd = (*cmd);
	if (tmp->llisttok->type == CHAR_GREATER || tmp->llisttok->type == CHAR_LESSER)
	{	
		init(cmd);
		(*cmd)->redir = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->redir;
		(*cmd)->previous = tmp_cmd;
		(*cmd)->previous->type_redir = (*cmd)->previous->type_redir == CHAR_GREATER ? 3 : tmp->llisttok->type;
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
