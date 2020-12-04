/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_memory_from_lexer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:25:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/03 22:57:22 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"


static void	freeing_memory_from_tok(t_tok **llistok)
{
// 	if (llistok)
// 	{
// 		free(llistok->data);
// 		llistok->data = NULL;
// 		freeing_memory_from_tok(llistok->next);
// 		free(llistok);
// 		llistok = NULL;
// 	}

	t_tok	*dell;
	t_tok	*plst;

	if (llistok)
	{
		plst = *llistok;
		while (plst)
		{
			dell = plst;
			plst = plst->next;
			free(dell->data);
			dell->data = NULL;
			free(dell);
			dell = NULL;
		}
		*llistok = NULL;
	}

}

void		freeing_memory_from_lexer(t_lexer **lexerbuf)
{
	if (!lexerbuf)
		return;
	freeing_memory_from_tok(&(*lexerbuf)->llisttok);
	free(*lexerbuf);
	*lexerbuf = NULL;
}
