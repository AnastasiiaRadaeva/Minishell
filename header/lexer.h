/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:17:30 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/08 11:11:01 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

# define TOKEN_TYPE "|&\'\"; ><0$"
# define ERR_1 "minishell: syntax error near unexpected token "
# define ERR_2 "minishell.: filename argument required\n .: usage: . filename [arguments]\n"
# define ERR_3 "minishell: : No such file or directory\n"

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

/*
** arr is array of counters and flags
** arr[0] - i - count for the input
** arr[1] - j - count for the data in t_tok;
** arr[2] - ntemptok
** arr[3] - state
** arr[4] - chtype
** arr[5] - k - count
*/
int lexer_build(char *input, int size, t_lexer  *lexerbuf);
void freeing_memory_from_lexer(t_lexer **lexerbuf);
int			check_syntax(t_lexer *lexerbuf);
int			get_char_type(char *ch_type);
void	if_state_in_general(t_tok **token, int *arr, char c, int size);
int		if_state_in_dollar(t_tok **token, int *arr, char c);
void	if_char_dollar(t_tok **token, int *arr, char c);
int		check_char_separator(int chtype);
void	if_char_null(t_tok **token, int *arr, char c);
int		if_state_in_quote(t_tok **token, int *arr, char c);
int		if_state_in_dquote(t_tok **token, int *arr, char c);
void	if_char_separator(t_tok **token, int *arr, int size);
void	if_char_whitespace(t_tok **token, int *arr, int size);
void	if_char_general(t_tok **token, int *arr, char c);
void 	if_char_dquote(t_tok **token, int *arr);
void	if_char_quote(t_tok **token, int *arr);

#endif
