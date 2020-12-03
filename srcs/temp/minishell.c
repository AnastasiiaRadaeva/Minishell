/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/03 19:23:26 by kbatwoma         ###   ########.fr       */
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
			// flag = 0;
			print_promt_string();
			// signal(SIGINT,signal_handler);
			read_cmd(data, &line);
			lexer_build(line, ft_strlen(line), lexerbuf);
			ft_free_tmp(line);
			syntax_tree = parse(data, lexerbuf);
			executor(syntax_tree, data);
			// if (flag == 0 && syntax_tree->num_cmd != CMD_IN_PATH)
			// 	write(1, "\n", 1);
			// if (*line == '\0')
				// print_promt_string();
			freeing_memory_from_lexer(lexerbuf);
			// free_syntax_tree(syntax_tree);
			// else
			// {
			// 	print_result(cmd, line);
			// 	// print_promt_string();
			// } 
			freeing_memory_from_struct_commands(syntax_tree);
		}
	}
	exit(EXIT_SUCCESS);
}