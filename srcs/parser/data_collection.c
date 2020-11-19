/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:25:08 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/19 17:26:15 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#if 0
void			init_arg(t_commands *cmd)
{
	t_list			*tmp;

	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;
}

static void			add_list(t_commands *cmd, t_data *data, char **line,
								size_t size)
{
	t_list			*new_list;
	char			*new_line;

	if (!(new_line = ft_strndup(*line, size)))
		error_output(cmd, data, NULL);
	if (!(new_list = ft_lstnew(new_line)))
		error_output(cmd, data, NULL);
	ft_lstadd_back(&cmd->lst, new_list);
	*line += size;
	*line = skip_spaces(*line);
}

static void		creat_lst(t_commands *cmd, t_data *data, char *line)
{
	char		*p_s;
	
	(void)data;
	if (!(*line))
		error_output(cmd, data, NULL);
	while (*line)
	{
		if ((p_s = ft_strchr2(line, SPECSYMBOL)))
		{
			if (*p_s == ' ')
				add_list(cmd, data, &line, p_s - line);
			else if (*p_s == '\'')
				add_list(cmd, data, &line, move_pointer(cmd, data, p_s, line));
			else if (*p_s == '\"')
				add_list(cmd, data, &line, move_pointer(cmd, data, p_s, line));
		}
		else
			add_list(cmd, data, &line, ft_strlen(line));
	}
}

static	size_t	find_end_of_command(char *line)
{
	char		*p;
	
	p = line;
	while (*p && !(ft_strchr(SEPARATORS, *p)))
	{
		if (*p == '\'')
		{
			p++;
			while (*p && *p != '\'')
				p++;
		}
		else if (*p && *p == '\"')
		{
			p++;
			while (*p != '\"')
				p++;
		}
		p++;
	}
	return (p - line);
}

void			data_collection(t_commands *cmd, t_data *data, char **line)
{
	size_t		len_cmd;
	char		*command;

	*line = skip_spaces(*line);
	len_cmd = find_end_of_command(*line);
	if (!(command = ft_strndup(*line, len_cmd)))
		error_output(cmd, data, NULL);
	creat_lst(cmd, data, command);
	*line += len_cmd;
	init_cmd(cmd);
	init_arg(cmd);
	cmd->count_args = ft_lstsize(cmd->lst);
	ft_free_tmp(command);
}

#endif
