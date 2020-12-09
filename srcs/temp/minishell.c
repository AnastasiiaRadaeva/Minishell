/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 14:31:31 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

int	g_global_status = 0;

static void	parser_and_executor(t_commands **syntax_tree, t_data **data,\
															t_lexer **lexerbuf)
{
	*syntax_tree = parse(*data, *lexerbuf);
	executor(*syntax_tree, *data);
	freeing_memory_from_lexer(lexerbuf);
	freeing_memory_from_struct_commands(syntax_tree);
}

int			main(int argc, char **argv, char **envp)
{
	char			*line;
	t_data			*data;
	t_commands		*syntax_tree;
	t_lexer			*lexerbuf;

	(void)argc;
	(void)argv;
	data = init_struct_data();
	create_env(data, envp);
	while (1)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		print_promt_string();
		read_cmd(data, &line);
		lexerbuf = (t_lexer *)ft_calloc(sizeof(t_lexer), 1);
		lexer_build(line, ft_strlen(line), lexerbuf);
		if (check_syntax(lexerbuf))
			;
		else
			parser_and_executor(&syntax_tree, &data, &lexerbuf);
		ft_free_tmp(line);
	}
	exit(EXIT_SUCCESS);
}
