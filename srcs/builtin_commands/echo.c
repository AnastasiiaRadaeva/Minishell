/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:48:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/11 16:32:44 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_join_all_args(t_commands *cmd, t_list *start, int flag)
{
	char	*line_for_print;
	char	*temp_line;

	if (!(line_for_print = ft_strdup("")))
		error_output(cmd, MALLOC_6);
	if (cmd->count_args > 0)
		while (start)
		{
			temp_line = line_for_print;
			if (!(line_for_print = ft_strjoin(line_for_print, start->content)))
				error_output(cmd, MALLOC_6); //добавить в параметры строку, которую можно потом очистить (чтобы не засорять строками) 
			free(temp_line);
			temp_line = line_for_print;
			if (!(line_for_print = start->next ? ft_strjoin(line_for_print, " ") : line_for_print))
					error_output(cmd, MALLOC_6);
			free(temp_line);
			start = start->next;
		}
	if (flag == 0)
	{
		temp_line = line_for_print;
		if (!(line_for_print = ft_strjoin(line_for_print, "\n")))
			error_output(cmd, MALLOC_6);
		free(temp_line);
	}
	return (line_for_print);
}

char	*ft_echo(t_commands *cmd) 
/*в print_result нужно убрать \n в конце строки и добавлять их уже при обработке функциями
*/
{
	char	end_of_string;
	char	*line_for_print;
	int		flag;
	t_list	*start;

	flag = 0;
	end_of_string = '\n';
	start = cmd->lst;
	if (ft_strcmp(cmd->lst->content, "-n") == 0)
	{
		flag = 1;
		start = cmd->lst->next;
		cmd->count_args--;
	}
	return (line_for_print = ft_join_all_args(cmd, start, flag));
}
