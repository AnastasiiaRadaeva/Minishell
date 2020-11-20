/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcustard <kcustard@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:48:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/20 17:59:40 by kcustard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*Функция выдает поданные аргументы через пробел. 
*Если нет флага -n, функция добавляет \n на конце строкию
*Возвращает требуемую строку.
*В случае ошибки функция печатает строку ошибки и вызывает error_output.
*Нужно подумать, как выводить эту ошибку, думаю, что тут нужен exit.
*К этому моменту все $ уже должны быть обработаны.
*В функцию должны подаваться уже готовые аргументы.
*/

#include "../../header/minishell.h"

void	error_output(t_commands *cmd, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
int		ft_strcmp(const char *s1, const char *s2);

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
			if (ft_strcmp(temp_line, line_for_print) != 0)
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
	int		flag;
	t_list	*start;

	flag = 0;
	start = cmd->lst;
	if (ft_strcmp(cmd->lst->content, "-n") == 0)
	{
		flag = 1;
		start = cmd->lst->next;
		cmd->count_args--;
	}
	return (ft_join_all_args(cmd, start, flag));
}
