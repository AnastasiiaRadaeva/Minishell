/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:28:36 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 15:36:57 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	if_char_quote(t_tok **token, int *arr)
{
	arr[3] = STATE_IN_QUOTE;
	(*token)->data[arr[1]] = CHAR_QOUTE;
	(*token)->type = CHAR_QOUTE;
	arr[1]++;
}

void	if_char_dquote(t_tok **token, int *arr)
{
	arr[3] = STATE_IN_DQUOTE;
	(*token)->data[arr[1]] = CHAR_DQUOTE;
	(*token)->type = CHAR_DQUOTE;
	arr[1]++;
}
