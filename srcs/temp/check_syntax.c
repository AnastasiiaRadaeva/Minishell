/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:39:42 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/05 20:39:02 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
# include "../libft/header/libft.h"

static	int	check_doubl(t_tok *next)
{
	if (next->next)
	{
		if (*next->next->data == *next->data)
			return (1);
	}
	return (0);
}

static	int	print_error(char *err, char *sym)
{
	ft_putstr(err);
	ft_putstr(sym);
	return (1);
}

static int	chek_one(t_tok *tok, int i)
{
	char 	*e;

	if (*tok->data == ';' && (*tok->next->data == ';' || i == 1))
		return (print_error(ERR_1, e = check_doubl(tok->next) ? "`;;'\n" : "`;'\n"));
	if ((*tok->data == ';' || *tok->data == '>') && ((*tok->next->data == '>' ||
		*tok->next->data == ';') || i == 1))
		return (print_error(ERR_1, e = check_doubl(tok->next) ? "`;;'\n" : "`;'\n"));
	if (*tok->data == '>' && !*tok->next->data  && !tok->next->next)
		return (print_error(ERR_1, "`newline'\n"));
	if (*tok->data == '>' && *tok->next->data == '>' && !*tok->next->next->data)
		return (print_error(ERR_1, "`newline'\n"));
	if (*tok->data != '>' && *tok->next->data == '>' && !*tok->next->next->data)
		return (print_error(ERR_1, "`newline'\n"));
	if (*tok->data != '>' && *tok->next->data == '>'
		&& *tok->next->next->data == '>' && !*tok->next->next->next->data)
		return (print_error(ERR_1, "`newline'\n"));
	return (0);
}

int			check_syntax(t_lexer *lexerbuf)
{
	t_tok 	*tok;
	int		i;
	// char	*e;

	i = 0;
	tok = lexerbuf->llisttok;
	while (tok && ++i)
	{
		if (tok->next)
		{
			if (i == 1 || *tok->data == ';')
				if (chek_one(tok, i))
					return (1);
				
			// if ((*tok->data == '>') && (*tok->next->data == '>'))
			// 	return (print_error(ERR_1, e = check_doubl(tok->next) ? "`>'\n" : "`newline'\n"));
			// if (*tok->data != '>' && *tok->next->data == '>' && i == 1)
			// 	return (print_error(ERR_1, "`newline'\n"));		
		}
		tok = tok->next;
	}	
	return (0);
	
}