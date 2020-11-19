/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/19 22:09:50 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"
#include "lexer.h"

#if 0
int    			main(int argc, char **argv, char **envp)
{
	char		*line;
	t_data		*data;
	t_commands	*cmd;

	(void)argc;
	(void)argv;
	(void)envp;
	data = init_struct_data();
	// create_env_v(&all, envp);
	signal(SIGINT,signal_handler);
	while (1)
	{
		print_promt_string();
		read_cmd(data, &line);
		cmd = create_tree(data, line);
		
		/*
		** print contents of cmd
		*/
		// #if 0
		t_commands *tmp = cmd;
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
		}
		// #endif


		if (line == '\0')
			print_promt_string();
		else
		{
			print_result(cmd, line);
			// print_promt_string();
		} 
		// freeing_memory_from_struct_commands(cmd);
	}
	exit(EXIT_SUCCESS);
}
#endif 

int    				main(int argc, char **argv, char **envp)
{
	char			*line;
	t_data			*data;
	t_commands		*cmd;
	t_lexer			lexerbuf;
	
	(void)argc;
	(void)argv;
	(void)envp;
	data = init_struct_data();
	// create_env_v(&all, envp);
	while (1)
	{
		print_promt_string();
		signal(SIGINT,signal_handler);
		read_cmd(data, &line);
		// cmd = create_tree(data, line);
		lexer_build(line, ft_strlen(line), &lexerbuf);
		ft_free_tmp(line);
		cmd = parse(data, &lexerbuf);
		
		/*
		** print contents of cmd
		*/
		// #if 0
		t_commands *tmp = cmd;
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
		// #endif


		if (line == '\0')
			print_promt_string();
		else
		{
			print_result(cmd, line);
			// print_promt_string();
		} 
		// freeing_memory_from_struct_commands(cmd);
	}
	exit(EXIT_SUCCESS);
}