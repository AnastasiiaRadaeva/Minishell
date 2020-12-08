/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst_to_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:23:29 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/08 21:01:59 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	if_type_dollar_add(char **content, char flag, char **p, int *i)
{
	if (flag == 'a')
	{
		ft_free_tmp(*content);
		*content = ft_strdup("");
	}
	else
	{
		*(p++);
		*i = ((*p)[(*i)] == '_' || ft_isalpha((*p)[(*i)])) ? 1 : 0;
	}
}

static void	if_type_dollar(t_data *data, char **content, char *rem, int i)
{
	char		*p;
	int			num_env;

	p = rem ? ft_strchr(rem, CHAR_DOLLAR) : ft_strchr(*content, CHAR_DOLLAR);
	if (p)
	{
		// p++;
		// i = (p[i] == '_' || ft_isalpha(p[i])) ? 1 : 0;
		if_type_dollar_add(content, 'b', &p, &i);
		if (i)
		{
			while (p[i] == '_' || ft_isalnum(p[i]))
				i++;
			if ((num_env = check_env(data->envp, p, i)))
			{
				p--;
				*p = '\0';
				rem = ft_strdup(p + i + 1);
				*content = ft_strjoin_gnl(content,\
												data->envp[num_env] + i + 1);
				if (*rem != '\0')
					if_type_dollar(data, content, rem, 0);
			}
			else
			// {
			// 	ft_free_tmp(*content);
			// 	*content = ft_strdup("");
			// }
				if_type_dollar_add(content, 'a', &p, &i);
		}
	}
	ft_free_tmp(rem);
}

static void	add_lst_to_node(t_commands **syntax_tree, t_data *data,
								char **content, int type)
{
	if (type == CHAR_DQUOTE)
		if_type_dollar(data, content, NULL, 0);
	strip_quotes_2(*content, ft_strlen(*content), 0);
	if (type == CHAR_DOLLAR)
		if_type_dollar(data, content, NULL, 0);
	if (*content)
		ft_lstadd_back(&(*syntax_tree)->lst, ft_lstnew(ft_strdup(*content)));
}

static void	init_pipe_or_semicolon(t_commands **cmd, t_data *data, char symb)
{
	if (symb == 's')
	{
		init(cmd, data);
		(*cmd)->next = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->next;
	}
	else
	{
		init(cmd, data);
		(*cmd)->pipe = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->pipe;
	}
}

void		add_nodes(t_commands **cmd, t_tok *llisttok, t_data *data)
{
	t_commands	*tmp_cmd;

	tmp_cmd = (*cmd);
	if (llisttok->type == CHAR_GREATER || llisttok->type == CHAR_LESSER)
	{
		init(cmd, data);
		(*cmd)->type_redir = llisttok->type;
		if ((*cmd)->previous && !(*cmd)->cmd)
		{
			if ((*cmd)->previous->type_redir == CHAR_GREATER &&\
										(*cmd)->type_redir == CHAR_GREATER)
				(*cmd)->previous->type_redir = 3;
			(*cmd)->type_redir = 0;
			return ;
		}
		(*cmd)->redir = init_struct_commands(*cmd, data);
		(*cmd) = (*cmd)->redir;
		(*cmd)->previous = tmp_cmd;
	}
	else if (llisttok->type == CHAR_SEMICOLON)
		init_pipe_or_semicolon(cmd, data, 's');
	else if (llisttok->type == CHAR_PIPE)
		init_pipe_or_semicolon(cmd, data, 'p');
	else
		add_lst_to_node(cmd, data, &llisttok->data, llisttok->type);
}
