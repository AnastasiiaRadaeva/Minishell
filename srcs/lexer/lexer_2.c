/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:25:00 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 15:37:24 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	if_char_null(t_tok **token, int *arr, char c)
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

int		check_char_separator(int chtype)
{
	if (chtype == CHAR_SEMICOLON || chtype == CHAR_GREATER ||
		chtype == CHAR_LESSER || chtype == CHAR_AMPERSAND ||
		chtype == CHAR_PIPE)
		return (1);
	return (0);
}

void	if_char_dollar(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	(*token)->type = CHAR_DOLLAR;
	arr[3] = STATE_IN_DOLLAR;
	arr[1]++;
}

int		if_state_in_dollar(t_tok **token, int *arr, char c)
{
	if (check_char_separator(arr[4]) || arr[4] == CHAR_WHITESPACE)
	{
		arr[0]--;
		return (STATE_GENERAL);
	}
	(*token)->data[arr[1]] = c;
	arr[1]++;
	return (STATE_IN_DOLLAR);
}

void	if_state_in_general(t_tok **token, int *arr, char c, int size)
{
	if (arr[4] == CHAR_QOUTE)
		if_char_quote(token, arr);
	else if (arr[4] == CHAR_DQUOTE)
		if_char_dquote(token, arr);
	else if (arr[4] == CHAR_GENERAL)
		if_char_general(token, arr, c);
	else if (arr[4] == CHAR_WHITESPACE)
		if_char_whitespace(token, arr, size);
	else if (arr[4] == CHAR_DOLLAR)
		if_char_dollar(token, arr, c);
	else if ((check_char_separator(arr[4])))
		if_char_separator(token, arr, size);
}
