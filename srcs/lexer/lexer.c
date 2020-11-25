/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:32:07 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/25 18:51:20 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

t_tok		*init_tok_list()
{
	t_tok 	*new_list;

	if (!(new_list = (t_tok *)ft_calloc(sizeof(t_tok), 1)))
		error_output(NULL, NULL, MALLOC_1);
	return (new_list);
}

int			get_char_type(char *ch_type)
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

void 		strip_quotes(char *src, char *dest, size_t n, int j)
{
	size_t 	i;
	char	lastquote;
	char	c;

	i = -1;
	lastquote = 0;
	if (n <= 1)
	{
		ft_strcpy(dest, src);
		return;
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

#if 0
#endif

void	init_arr(int *arr)
{
	arr[0] = -1;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = STATE_GENERAL;
	arr[4] = 0;
	arr[5] = 0;
}


void	_if_char_quote(t_tok **token, int *arr)
{
	arr[3] = STATE_IN_QUOTE;
	(*token)->data[arr[1]] = CHAR_QOUTE;
	(*token)->type = CHAR_QOUTE;
	arr[1]++;
}

void 	_if_char_dquote(t_tok **token, int *arr)
{
	arr[3] = STATE_IN_DQUOTE;
	(*token)->data[arr[1]] = CHAR_DQUOTE;
	(*token)->type = CHAR_DQUOTE;
	arr[1]++;
}

void	_if_char_general(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	(*token)->type = TOKEN;
	arr[1]++;
}

void	_if_char_whitespace(t_tok **token, int *arr, int size)
{
	if (arr[1] > 0)
	{
		(*token)->data[arr[1]] = 0;
		(*token)->next = init_tok_list();
		*token = (*token)->next;
		(*token)->data = malloc(size - arr[0] + 1);
		(*token)->data[0] = 0;
		(*token)->type = CHAR_NULL;
		arr[1] = 0;
	}
}

void	_if_char_separator(t_tok **token, int *arr, int size)
{
	if (arr[1] > 0)
	{
		(*token)->data[arr[1]] = 0;
		(*token)->next = init_tok_list();
		*token = (*token)->next;
		(*token)->data = malloc(size - arr[0] + 1);
		(*token)->data[0] = 0;
		(*token)->type = CHAR_NULL;
		arr[1] = 0;
	}
	(*token)->data[0] = arr[4];
	(*token)->data[1] = 0;
	(*token)->type = arr[4];
	(*token)->next = init_tok_list();
	*token = (*token)->next;
	(*token)->data = malloc(size - arr[0] + 1);
	(*token)->data[0] = 0;
	(*token)->type = CHAR_NULL;
	arr[1] = 0;
}

int		_if_state_in_dquote(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	arr[1]++;
	if (arr[4] == CHAR_DQUOTE)
		return (STATE_GENERAL);
	return (STATE_IN_DQUOTE);
}

int		_if_state_in_quote(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	arr[1]++;
	if (arr[4] == CHAR_QOUTE)
		return (STATE_GENERAL);
	return (STATE_IN_QUOTE);
}

void	_if_char_null(t_tok **token, int *arr, char c)
{	
	int	chtype;

	chtype = get_char_type(ft_strchr(TOKEN_TYPE, c));
	if (chtype == CHAR_NULL)
	{	
		if (arr[1] > 0)
		{
			(*token)->data[arr[1]] = 0;
			arr[2]++;
			arr[1] = 0;
		}
	}
}

int		_check_char_separator(int chtype)
{
	if (chtype == CHAR_SEMICOLON || chtype == CHAR_GREATER ||
		chtype == CHAR_LESSER || chtype == CHAR_AMPERSAND ||
		chtype == CHAR_PIPE)
		return (1);
	return (0);
}

void	_if_char_dollar(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	(*token)->type = CHAR_DOLLAR;
	arr[3] = STATE_IN_DOLLAR;
	arr[1]++;
}

int		_if_state_in_dollar(t_tok **token, int *arr, char c)
{
	if (_check_char_separator(arr[4]) || arr[4] == CHAR_WHITESPACE)
	{
		arr[0]--;
		return (STATE_GENERAL);
	}
	(*token)->data[arr[1]] = c;
	arr[1]++;
	return (STATE_IN_DOLLAR);

	
}

void	_if_state_in_general(t_tok **token, int *arr, char c, int size)
{
	if (arr[4] == CHAR_QOUTE)
		_if_char_quote(token, arr);
	else if (arr[4] == CHAR_DQUOTE)
		_if_char_dquote(token, arr);
	else if (arr[4] == CHAR_GENERAL)
		_if_char_general(token, arr, c);
	else if (arr[4] == CHAR_WHITESPACE)
		_if_char_whitespace(token, arr, size);
	else if (arr[4] == CHAR_DOLLAR)
		_if_char_dollar(token, arr, c);
	else if ((_check_char_separator(arr[4])))
		_if_char_separator(token, arr, size);

}

void strip_quotes_in_lst(t_tok **token, int *arr)
{
	char *stripped;

	if ((*token)->type == TOKEN)
	{
		stripped = malloc(ft_strlen((*token)->data) + 1);
		strip_quotes((*token)->data, stripped, ft_strlen((*token)->data), 0);
		(*token)->data = stripped;
		arr[5]++;
	}
	(*token) = (*token)->next;
}

/*
** arr is array of counters and flags
** arr[0] - i - count
** arr[1] - j - count
** arr[2] - ntemptok
** arr[3] - state
** arr[4] - chtype
** arr[5] - k - count
*/

int lexer_build(char *input, int size, t_lexer  *lexerbuf)
{
	t_tok 	*token;
	int		arr[6];

	init_arr(arr);
	lexerbuf->llisttok = init_tok_list();
	token = lexerbuf->llisttok;
	tok_init(token, size);
	while (input[++arr[0]] != '\0')
	{
		arr[4] = get_char_type(ft_strchr(TOKEN_TYPE, input[arr[0]]));
		if (arr[3] == STATE_GENERAL)
			_if_state_in_general(&token, arr, input[arr[0]], size);
		else if (arr[3] == STATE_IN_DQUOTE)
			arr[3] = _if_state_in_dquote(&token, arr, input[arr[0]]);
		else if (arr[3] == STATE_IN_QUOTE)
			arr[3] = _if_state_in_quote(&token, arr, input[arr[0]]);
		else if (arr[3] == STATE_IN_DOLLAR)
			arr[3] = _if_state_in_dollar(&token, arr, input[arr[0]]);
	}
	_if_char_null(&token, arr, input[arr[0]]);
	token = lexerbuf->llisttok;
	// while (token)
		// strip_quotes_in_lst(&token, arr);
	lexerbuf->ntoks = arr[5];
	return (arr[5]);
}