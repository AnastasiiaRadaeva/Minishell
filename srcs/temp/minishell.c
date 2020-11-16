/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/16 16:42:58 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

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
		read_cmd(&line);
		cmd = create_list(data, line);
		
		/*
		** print contents of cmd
		*/
		#if 0
		while (cmd)
		{
			ft_putendl("---next output cmd->cmd---");
			ft_putendl(cmd->cmd);
			ft_putendl("---next output cmd->lst---");
			for (int i = 0, size = ft_lstsize(cmd->lst); i < size ; i++)
			{
				ft_putendl(cmd->lst->content);
				cmd->lst = cmd->lst->next;
			}
			if (cmd->next)
				cmd = cmd->next;
			else if (cmd->pipe)
				cmd = cmd->pipe;
			else if (cmd->redir)
				cmd = cmd->redir;
			else
				cmd = cmd->next;
		}
		#endif


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
