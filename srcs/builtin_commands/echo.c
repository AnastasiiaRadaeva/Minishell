/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:48:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/03 11:40:49 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_join_all_args(t_commands *cmd, t_list *start, int flag)
{
	char	*line_for_print;
	char	*temp_line;

	if (!(line_for_print = ft_strdup("")))
		error_output(cmd, NULL, MALLOC_6);
	if (cmd->count_args > 0)
		while (start)
		{
			temp_line = line_for_print;
			if (!(line_for_print = ft_strjoin(line_for_print, start->content)))
				error_output(cmd, NULL, MALLOC_6);
			free(temp_line);
			temp_line = line_for_print;
			if (!(line_for_print = start->next ? ft_strjoin(line_for_print, " ")\
									 : line_for_print))
					error_output(cmd, NULL, MALLOC_6);
			if (ft_strcmp(temp_line, line_for_print) != 0)
				free(temp_line);
			start = start->next;
		}
	if (flag == 0)
		line_for_print = ft_strjoin_gnl(&line_for_print, "\n");
	return (line_for_print);
}

void	ft_echo(t_commands *cmd)
{
	int		flag;
	char	*print_line;
	t_list	*start;

	flag = 0;
	start = cmd->lst;
	if (cmd->count_args > 0)
	{
		if (ft_strcmp(cmd->lst->content, "-n") == 0)
		{
			flag = 1;
			start = cmd->lst->next;
			cmd->count_args--;
		}
		else if (!ft_strcmp(cmd->lst->content, "$?"))
		{
			ft_putnbr_fd(errno, 0);
			write(1, "\n", 1);
			errno = 0;
			return;
		}
	}
	print_line = ft_join_all_args(cmd, start, flag);
	ft_putstr(print_line);
	ft_free_tmp(print_line);
}
