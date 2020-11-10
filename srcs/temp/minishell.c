/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 16:04:05 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int    			main(int argc, char **argv, char **envp)
{
    t_commands	*cmd;
	t_other		*all;
	char		*line;
	char		*new_line;
	
	(void)argc;
	(void)argv;
	cmd = NULL;
	signal(SIGINT,signal_handler);
	print_promt_string();
	while (1)
	{
		cmd = NULL;
		read_cmd(cmd, &line);
		create_list(&cmd, line, &new_line);
		if (*new_line == '\0')
			print_promt_string();
		else
		{
			print_result(&cmd, new_line);
			print_promt_string();
		} 
		freeing_memory_from_struct_commands(cmd);
	}
	exit(EXIT_SUCCESS);
}
