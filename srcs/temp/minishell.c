/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/04 09:31:40 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

int    				main(int argc, char **argv, char **envp)
{
	char			*line;
	t_data			*data;
	t_commands		*syntax_tree;
	t_lexer			*lexerbuf;
	
	(void)argc;
	(void)argv;
	data = init_struct_data();
	lexerbuf = (t_lexer *)ft_calloc(sizeof(t_lexer), 1);
	create_env(data, envp);
	
	/*
	**	for minishell_test
	*/
	#if 0
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		lexer_build(ft_strdup(argv[2]), ft_strlen(argv[2]), lexerbuf);
		syntax_tree = parse(data, lexerbuf);
		executor(syntax_tree, data);
	}
	else
	#endif
	{
		while (1)
		{
			signal(SIGINT, signal_handler);
			signal(SIGQUIT, signal_handler);
			print_promt_string();
			read_cmd(data, &line);
			lexer_build(line, ft_strlen(line), lexerbuf);
			ft_free_tmp(line);
			syntax_tree = parse(data, lexerbuf);
			executor(syntax_tree, data);
			freeing_memory_from_lexer(&lexerbuf);
			freeing_memory_from_struct_commands(syntax_tree);
			freeing_memory_from_struct_data(data);
		}
	}
	exit(EXIT_SUCCESS);
}