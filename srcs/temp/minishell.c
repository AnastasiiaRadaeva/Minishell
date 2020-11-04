/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:00:57 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/04 15:42:16 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int    			main(int argc, char **argv, char **environ)
{
    t_commands	*cmd;
	char		*line;

	(void)argc;
	(void)argv;
	(void)environ;
	init_struct_commands(cmd);
	signal(SIGINT,signal_handler);
	while (1)
	{
		print_promt_string();
		read_cmd(cmd, &line);
		creat_list(cmd, line);
		ft_free_tmp(line);
		free(cmd);
	}
	exit(EXIT_SUCCESS);
}