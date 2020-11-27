/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/26 18:56:24 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"

#if 0
#endif 

int    				main(int argc, char **argv, char **envp)
{
	char			*line;
	t_data			*data;
	t_commands		*syntax_tree;
	t_lexer			lexerbuf;
	
	(void)argc;
	(void)argv;
	(void)envp;
	data = init_struct_data();
	create_env(data, envp);
	
	/*
	**	for minishell_test
	*/
	#if 0
	if (argv[1][0] == '-' && argv[1][1] == 'c')
	{
		lexer_build(ft_strdup(argv[2]), ft_strlen(argv[2]), &lexerbuf);
		syntax_tree = parse(data, &lexerbuf);
		executor(syntax_tree, data);
	}
	else
	#endif
	{
		while (1)
		{
			print_promt_string();
			signal(SIGINT,signal_handler);
			read_cmd(data, &line);
			lexer_build(line, ft_strlen(line), &lexerbuf);
			ft_free_tmp(line);
			syntax_tree = parse(data, &lexerbuf);
	
			
			/*
			** print contents of cmd
			*/
			#if 0
			t_commands *tmp = syntax_tree;
			while (tmp)
			{
				ft_putendl("---next output cmd->cmd---");
				ft_putendl(tmp->cmd);
				ft_putendl("---next output cmd->lst---");
				for (int i = 0, size = ft_lstsize(tmp->lst); i < size ; i++)
				{
					ft_putendl(tmp->lst->content);
					tmp->lst = tmp->lst->next;
				}
				if (tmp->next)
					tmp = tmp->next;
				else if (tmp->pipe)
					tmp = tmp->pipe;
				else if (tmp->redir)
					tmp = tmp->redir;
				else
					tmp = tmp->next;
				ft_putendl("--------------------------");
			}
			#endif
			executor(syntax_tree, data);
	
			if (line == '\0')
				print_promt_string();
			freeing_memory_from_lexer(&lexerbuf);
			// free_syntax_tree(syntax_tree);
			// else
			// {
			// 	print_result(cmd, line);
			// 	// print_promt_string();
			// } 
			// freeing_memory_from_struct_commands(cmd);
		}
	}
	exit(EXIT_SUCCESS);
}