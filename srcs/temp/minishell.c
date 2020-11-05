/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 14:05:42 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int    			main(int argc, char **argv, char **environ)
{
    t_commands	*cmd;
	char		*line;
	char		*new_line;
	
	(void)argc;
	(void)argv;
	(void)environ;
	cmd = NULL;
	signal(SIGINT,signal_handler);
	print_promt_string();
	while (1)
	{
		read_cmd(cmd, &line);
		create_list(&cmd, line, &new_line);
		if (*new_line == '\0')
			print_promt_string();
		else
		{
			print_result(cmd, new_line);
			print_promt_string();
		} 
		// free(cmd);
	}
	exit(EXIT_SUCCESS);
}