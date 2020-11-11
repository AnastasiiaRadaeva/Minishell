/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/11 16:48:27 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

#if 0
int    			main(int argc, char **argv, char **envp)
{
    t_commands	*cmd;
	// t_data		*all;
	char		*line;
	char		*new_line;
	
	(void)argc;
	(void)argv;
	(void)envp;
	cmd = NULL;
	// create_env_v(&all, envp);
	signal(SIGINT,signal_handler);
	print_promt_string();
	while (1)
	{
		cmd = NULL;
		read_cmd(cmd, &line);
		create_list(cmd, &line, &new_line);
		if (*new_line == '\0')
			print_promt_string();
		else
		{
			print_result(cmd, new_line);
			print_promt_string();
		} 
		// freeing_memory_from_struct_commands(cmd);
	}
	exit(EXIT_SUCCESS);
}
#endif 

int    			main(int argc, char **argv, char **envp)
{
    t_commands	*cmd;
	t_data		*all;
	char		*line;
	char		*new_line;
	
	all = NULL;
	create_env_v(&all, envp);
	print_promt_string();
	while (1)
	{
		
		print_result(cmd, new_line);
		print_promt_string();
	}
	exit(EXIT_SUCCESS);
}

