/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:32:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/07 15:36:00 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

int		get_char_type(char *ch_type)
{
	if ((ch_type) && *ch_type == '\'')
		return (CHAR_QOUTE);
	else if ((ch_type) && *ch_type == '\"')
		return (CHAR_DQUOTE);
	else if ((ch_type) && *ch_type == '|')
		return (CHAR_PIPE);
	else if ((ch_type) && *ch_type == '&')
		return (CHAR_AMPERSAND);
	else if ((ch_type) && *ch_type == ' ')
		return (CHAR_WHITESPACE);
	else if ((ch_type) && *ch_type == ';')
		return (CHAR_SEMICOLON);
	else if ((ch_type) && *ch_type == '>')
		return (CHAR_GREATER);
	else if ((ch_type) && *ch_type == '<')
		return (CHAR_LESSER);
	else if ((ch_type) && *ch_type == 0)
		return (CHAR_NULL);
	else if ((ch_type) && *ch_type == '$')
		return (CHAR_DOLLAR);
	return (CHAR_GENERAL);
}

void	strip_quotes(char *src, char *dest, size_t n, int j)
{
	size_t	i;
	char	lastquote;
	char	c;

	i = -1;
	lastquote = 0;
	if (n <= 1)
	{
		ft_strcpy(dest, src);
		return ;
	}
	while (++i < n)
	{
		c = src[i];
		if ((c == '\'' || c == '\"') && lastquote == 0)
			lastquote = c;
		else if (c == lastquote)
			lastquote = 0;
		else
			dest[j++] = c;
	}
	dest[j] = 0;
}

void	tok_init(t_tok *tok, int datasize)
{
	tok->data = malloc(datasize + 1);
	tok->data[0] = 0;
	tok->type = CHAR_NULL;
	tok->next = NULL;
}

void	init_arr(int *arr)
{
	arr[0] = -1;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = STATE_GENERAL;
	arr[4] = 0;
	arr[5] = 0;
}

int		lexer_build(char *input, int size, t_lexer *lexerbuf)
{
	t_tok	*token;
	int		arr[6];

	init_arr(arr);
	lexerbuf->llisttok = (t_tok *)ft_calloc(sizeof(t_tok), 1);
	token = lexerbuf->llisttok;
	tok_init(token, size);
	while (input[++arr[0]] != '\0')
	{
		arr[4] = get_char_type(ft_strchr(TOKEN_TYPE, input[arr[0]]));
		if (arr[3] == STATE_GENERAL)
			if_state_in_general(&token, arr, input[arr[0]], size);
		else if (arr[3] == STATE_IN_DQUOTE)
			arr[3] = if_state_in_dquote(&token, arr, input[arr[0]]);
		else if (arr[3] == STATE_IN_QUOTE)
			arr[3] = if_state_in_quote(&token, arr, input[arr[0]]);
		else if (arr[3] == STATE_IN_DOLLAR)
			arr[3] = if_state_in_dollar(&token, arr, input[arr[0]]);
	}
	if_char_null(&token, arr, input[arr[0]]);
	token = lexerbuf->llisttok;
	lexerbuf->ntoks = arr[5];
	return (arr[5]);
}
