/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 17:04:33 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_comand_line(t_commands *cmd, char **old_line, char **new_line)
{
	if (!(*new_line = ft_strtrim(*old_line, "\t\n\v\f\r  ")))
		error_output(cmd, MALLOC_2);
}


void	create_list(t_commands *cmd, char **line, char **new_line)
{
	init_struct_commands(cmd);
	ft_comand_line(cmd, line, new_line);
	// ft_free_tmp(line);
	// ft_spec_symb
	// return (cmd);
}

//kbatwoma
// static int	ft_skip_spases(char *line, char flag)
// {
// 	int index;

// 	if (flag == 's')
// 	{
// 		index = 0;
// 		while (ft_isspace(line[index]) == 1)
// 			index++;
// 	}
// 	if (flag == 'e')
// 	{
// 		index = ft_strlen(line) - 1;
// 		while (ft_isspace(line[index]) == 1)
// 			index--;
// 	}
// 	return (index);	
// }

// static void	ft_comand_line(t_commands **cmd, char *old_line, char **new_line)
// {
// 	int		index;

// 	index = ft_skip_spases(old_line, 's');
// 	old_line += index;
// 	index = ft_skip_spases(old_line, 'e');
// 	if (!(*new_line = ft_strndup(old_line, index + 1)))
// 		error_output(*cmd, MALLOC_2);
// }

// static t_commands *ft_create_cmd(void)
// {
// 	t_commands *cmd;

// 	if (!(cmd = (t_commands*)malloc(sizeof(t_commands))))
// 			error_output(cmd, MALLOC_3);
// 	cmd->cmd = NULL;
// 	cmd->cmd_dir = NULL;
// 	cmd->arg = NULL;
// 	cmd->dit_find = 0;
// 	cmd->type_redir = 0;
// 	cmd->invalid = 0;
// 	cmd->redir = NULL;
// 	cmd->pipe = NULL;
// 	cmd->next = NULL;
// 	return (cmd);
// }

// static void	ft_parse_mini_line(t_commands *cmd, char *old_line, int size)
// {
// 	char	*line;

// 	if ((line = ft_strndup(old_line, size)) == NULL)
// 		error_output(cmd, MALLOC_4);
// 	cmd->cmd = line;
// 	//нужно разбить линию на части и раскидать информацию в соответствии с этим
// }

// static t_commands	*ft_last_cmd(t_commands **cmd)
// {
// 	t_commands	*last_cmd;

// 	last_cmd = *cmd;
// 	while (last_cmd->next || last_cmd->redir || last_cmd->pipe)
// 		{
// 			if (last_cmd->next)
// 				last_cmd = last_cmd->next;
// 			if (last_cmd->pipe)
// 				last_cmd = last_cmd->pipe;
// 			if (last_cmd->redir)
// 				last_cmd = last_cmd->redir;
// 		}
// 	return (last_cmd);
// }

// static int	ft_divider(t_commands **cmd, char *line, int index, char divider)
// {
// 	t_commands	*tmp_cmd;
// 	t_commands	*last_cmd;

// 	tmp_cmd = ft_create_cmd();
// 	if (*cmd == NULL)
// 	{
// 		ft_parse_mini_line(tmp_cmd, line, index);
// 		*cmd = tmp_cmd;
// 	}
// 	else
// 	{
// 		last_cmd = ft_last_cmd(cmd);
// 		ft_parse_mini_line(tmp_cmd, line + 1, index - 1);
// 		if (divider == '|')
// 			last_cmd->pipe = tmp_cmd;
// 		if (divider == ';')
// 			last_cmd->next = tmp_cmd;
// 		if (divider == '>' || divider == '<')
// 			last_cmd->redir = tmp_cmd;
// 	}
// 	return (index);
// }

// static void	ft_divider_line(t_commands **cmd, char **line)
// {
// 	int	index;
// 	int start;

// 	index = 0;
// 	start = 0;
// 	while ((*line)[index++] != '\0')
// 		if ((*line)[index] == '|' || (*line)[index] == ';' || \
// 			(*line)[index] == '>' || (*line)[index] == '<' || \
// 			(*line)[index] == '\0')
// 			start += ft_divider(cmd, (*line) + start, index - start, (*line)[start]);
// }

// void	create_list(t_commands **cmd, char *line, char **new_line)
// {
// 	// init_struct_commands(cmd);
// 	ft_comand_line(cmd, line, new_line);
// 	ft_free_tmp(line);
// 	ft_divider_line(cmd, new_line);
// 	// return (cmd);
// }
