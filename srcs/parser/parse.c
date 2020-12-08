/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:19:04 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/08 20:52:47 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_env(char **envp, char *var, int size)
{
	int		i;
	int		j;
	int		recover_size;

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
				if ((envp[i][j + 1] == '=' || envp[i][j + 1] == '\0') &&\
																size == 1)
					return (i);
				j++;
				size--;
			}
		}
	}
	return (0);
}

void		strip_quotes_2(char *content, size_t n, int j)
{
	size_t	i;
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

t_commands	*parse(t_data *data, t_lexer *lexerbuf)
{
	t_commands	*syntax_tree;
	t_commands	*tmp;
	t_tok		*tmp_1;

	syntax_tree = NULL;
	syntax_tree = init_struct_commands(syntax_tree, data);
	tmp = syntax_tree;
	tmp_1 = lexerbuf->llisttok;
	while (tmp_1)
	{
		add_nodes(&tmp, tmp_1, data);
		tmp_1 = tmp_1->next;
	}
	if (!syntax_tree->next && !syntax_tree->redir && !syntax_tree->pipe)
		init(&syntax_tree, data);
	if (!tmp->next && !tmp->redir && !tmp->pipe && syntax_tree != tmp)
		init(&tmp, data);
	return (syntax_tree);
}
