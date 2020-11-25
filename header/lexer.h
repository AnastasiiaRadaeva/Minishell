/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:17:30 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/25 15:58:46 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

# define TOKEN_TYPE "|&\'\"; ><0$"


typedef	enum		e_token_type
{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_QOUTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_SEMICOLON = ';',
	CHAR_WHITESPACE = ' ',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	CHAR_DOLLAR = '$',
	TOKEN = -1,
}					t_token_type;

enum {
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
	STATE_IN_DOLLAR,
	STATE_GENERAL,
};

typedef	struct		s_tok 
{
	char 			*data;
	int 			type;
	struct s_tok	*next;
}					t_tok;

typedef	struct		s_lexer
{
	t_tok	*llisttok;
	int 	ntoks;
}					t_lexer;

int lexer_build(char *input, int size, t_lexer  *lexerbuf);
void freeing_memory_from_lexer(t_lexer *lexerbuf);
#endif
