/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:28:07 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 15:35:06 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	if_char_general(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	(*token)->type = TOKEN;
	arr[1]++;
}

void	if_char_whitespace(t_tok **token, int *arr, int size)
{
	if (arr[1] > 0)
	{
		(*token)->data[arr[1]] = 0;
		(*token)->next = (t_tok *)ft_calloc(sizeof(t_tok), 1);
		*token = (*token)->next;
		(*token)->data = malloc(size - arr[0] + 1);
		(*token)->data[0] = 0;
		(*token)->type = CHAR_NULL;
		arr[1] = 0;
	}
}

void	if_char_separator(t_tok **token, int *arr, int size)
{
	if (arr[1] > 0)
	{
		(*token)->data[arr[1]] = 0;
		(*token)->next = (t_tok *)ft_calloc(sizeof(t_tok), 1);
		*token = (*token)->next;
		(*token)->data = malloc(size - arr[0] + 1);
		(*token)->data[0] = 0;
		(*token)->type = CHAR_NULL;
		arr[1] = 0;
	}
	(*token)->data[0] = arr[4];
	(*token)->data[1] = 0;
	(*token)->type = arr[4];
	(*token)->next = (t_tok *)ft_calloc(sizeof(t_tok), 1);
	*token = (*token)->next;
	(*token)->data = malloc(size - arr[0] + 1);
	(*token)->data[0] = 0;
	(*token)->type = CHAR_NULL;
	arr[1] = 0;
}

int		if_state_in_dquote(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	arr[1]++;
	if (arr[4] == CHAR_DQUOTE)
		return (STATE_GENERAL);
	return (STATE_IN_DQUOTE);
}

int		if_state_in_quote(t_tok **token, int *arr, char c)
{
	(*token)->data[arr[1]] = c;
	arr[1]++;
	if (arr[4] == CHAR_QOUTE)
		return (STATE_GENERAL);
	return (STATE_IN_QUOTE);
}
