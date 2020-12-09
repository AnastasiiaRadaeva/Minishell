/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst_to_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:23:29 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/09 13:11:13 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	if_type_dollar_add(char **content, char flag, char *p, int *i)
{
	if (flag == 'a')
	{
		ft_free_tmp(*content);
		*content = ft_strdup("");
	}
	else
		*i = (p[(*i)] == '_' || ft_isalpha(p[(*i)])) ? 1 : 0;
}

static void	if_type_dollar(t_data *data, char **c, char **rem, int i)
{
	char		*p;
	int			num_env;
	char		*tmp;

	p = *rem ? ft_strchr(*rem, CHAR_DOLLAR) : ft_strchr(*c, CHAR_DOLLAR);
	if (p)
	{
		if_type_dollar_add(c, 'b', ++p, &i);
		if (i)
		{
			while (p[i] == '_' || ft_isalnum(p[i]))
				i++;
			if ((num_env = check_env(data->envp, p--, i)))
			{
				*p = '\0';
				tmp = *rem;
				*rem = ft_strdup(p + i + 1);
				free(tmp);
				*c = ft_strjoin_gnl(c, data->envp[num_env] + i + 1);
				**rem != '\0' ? if_type_dollar(data, c, rem, 0) : NULL;
			}
			else
				if_type_dollar_add(c, 'a', ++p, &i);
		}
	}
}

static void	add_lst_to_node(t_commands **syntax_tree, t_data *data,
								char **content, int type)
{
	char *rem;

	rem = NULL;
	if (type == CHAR_DQUOTE)
	{
		if_type_dollar(data, content, &rem, 0);
		if (rem != NULL)
		{
			free(rem);
			rem = NULL;
		}
	}
	strip_quotes_2(*content, ft_strlen(*content), 0);
	if (type == CHAR_DOLLAR)
	{
		if_type_dollar(data, content, &rem, 0);
		if (rem != NULL)
		{
			free(rem);
			rem = NULL;
		}
	}
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
