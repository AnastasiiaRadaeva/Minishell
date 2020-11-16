/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/16 15:30:35 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
// #if 0
//anatashi


#if 0
static void split_string_into_arguments(t_commands *cmd, char *new_line)
{
	char 	*p_s;
	static	char	*p_w;

	while ((p_w = (p_s = ft_strchr2(new_line, SPECSYMBOL)) ? move_pointer(p_w, p_s) : NULL))
	{
		if (*p_s == '\'')
			add_list(&cmd->lst, p_s, p_w - p_s);
		else if (*p_s == ' ')
			add_list(&cmd->lst, new_line, p_s - new_line);
		new_line += p_w - new_line;
	}
	if (*new_line)
		add_list(&cmd->lst, new_line, ft_strlen(new_line));

	#if 0
		/*
		**	print result of the function
		*/

		t_list *tmp;
		tmp = cmd->lst;
		while (tmp)
		{
			ft_putendl(tmp->content);
			tmp = tmp->next;
		}

	#endif
}
#endif


#if 0

static char	find_end_cmd(char *new_line, char *separators)
{
	while (*new_line && !(ft_strchr(separators, *new_line)))
	{
		if (*new_line == '\\')
			new_line++;
	 	if (*new_line += *new_line == '\'' ? 1 : 0)
		{
			while (*new_line && !(ft_strchr("\'", *new_line)))
				new_line++;
			return (*new_line);
		}
		else if (*new_line += *new_line == '\"' ? 1 : 0)
		{
			while (*new_line && !(ft_strchr("\"", *new_line)))
				new_line++;
			return (*new_line);
		}
		new_line++;
	}
	return (*new_line);
}

#endif
#if 0
static void	remove_spaces_in_string(t_commands *cmd, char **line)
{
	char	*tmp;

	tmp = *line;
	if (!(*line = ft_strtrim(*line, WHITESPACES)))
		error_output(cmd, MALLOC_2);
	ft_free_tmp(tmp);
}

static int	checking_cmd(char *cmd)
{
	char 	*tmp;
	size_t	i;

	i = -1;
	tmp = cmd;
	while (tmp[++i])
	{
		if (ft_isalpha(tmp[i]))
		{
			if (tmp[i] >= 'A' && tmp[i] <= 'Z')
				tmp[i] += 32;
		}
	}
	if (tmp[i])
		return (-1);
	return (checking_cmd_for_tocken(tmp));
}

static void init_cmd(t_commands *cmd)
{
	cmd->cmd = cmd->lst->content;
	cmd->invalid = checking_cmd(&cmd->cmd);
	cmd->num_cmd = cmd->invalid > 0 ? cmd->invalid : 0;
}

// #if 0
static void	init_arg(t_commands *cmd)
{
	t_list	*tmp;

	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;


}
// #endif

//kbatwoma
static void	ft_parse_mini_line(t_commands *cmd, char *old_line, int size)
{
	char	*line;

	if ((line = ft_strndup(old_line, size)) == NULL)
		error_output(cmd, MALLOC_4);
	create_args(cmd, &line, &line) //  первая line не нужна
	//нужно разбить линию на части и раскидать информацию в соответствии с этим
}

static t_commands	*ft_last_cmd(t_commands **cmd)
{
	t_commands	*last_cmd;

	last_cmd = *cmd;
	while (last_cmd->next || last_cmd->redir || last_cmd->pipe)
		{
			if (last_cmd->next)
				last_cmd = last_cmd->next;
			if (last_cmd->pipe)
				last_cmd = last_cmd->pipe;
			if (last_cmd->redir)
				last_cmd = last_cmd->redir;
		}
	return (last_cmd);
}

static int	ft_divider(t_commands **cmd, char *line, int index, char divider)
{
	t_commands	*tmp_cmd;
	t_commands	*last_cmd;

	tmp_cmd = init_struct_commands();
	if (*cmd == NULL)
	{
		ft_parse_mini_line(tmp_cmd, line, index);
		*cmd = tmp_cmd;
	}
	else
	{
		last_cmd = ft_last_cmd(cmd);
		ft_parse_mini_line(tmp_cmd, line + 1, index - 1);
		if (divider == '|')
			last_cmd->pipe = tmp_cmd;
		if (divider == ';')
			last_cmd->next = tmp_cmd;
		if (divider == '>' || divider == '<')
			last_cmd->redir = tmp_cmd;
	}
	return (index);
}

static void	ft_divider_line(t_commands **cmd, char **line)
{
	int	index;
	int start;

	index = 0;
	start = 0;
	while ((*line)[index++] != '\0')
		if ((*line)[index] == '|' || (*line)[index] == ';' || \
			(*line)[index] == '>' || (*line)[index] == '<' || \
			(*line)[index] == '\0')
			start += ft_divider(cmd, (*line) + start, index - start, (*line)[start]);
}

void		creat_first_node(t_commands *cmd, char *line, size_t size)
{
	if (!(cmd = (t_commands *)ft_calloc(sizeof(t_commands), 1)))
		error_output(cmd, MALLOC_1);
	if (!(cmd->cmd = ft_strndup(line, size)))
		error_output(cmd, MALLOC_1);
	cmd->lst = split_cmd(cmd, cmd->cmd);
	ft_free_tmp(cmd->cmd);
	init_cmd(cmd);
	

}

#endif

#if 0
#endif
	#if 0
static	void		add_node(t_commands *cmd, char *line, size_t size)
{
	if (!cmd)
		creat_node(cmd, line, size);
}

static	void		split_string_into_arguments(t_commands *cmd, char **line)
{
	char 			*p_s;
	static char		*p_w;

	while ((p_w = (p_s = ft_strchr2(line, TMP)) ? move_pointer_1(p_w, p_s) : NULL))
	{
		if (*p_s == '\'')
			add_list(cmd->lst, p_s, p_w - p_s);
		else if (*p_s = ';')
			add_node(cmd, p_s, p_w - p_s);
		else if (*p_s == ' ')
			add_list(&cmd->lst, line, p_s - line);
		line += p_w - line;
	}
	if (*line)
		add_list(&cmd->lst, line, ft_strlen(line));

		/*
		**	print result of the function
		*/

		t_list *tmp;
		tmp = cmd->lst;
		while (tmp)
		{
			ft_putendl(tmp->content);
			tmp = tmp->next;
		}

}
	#endif	
/*
**	add argument count
*/

#if 0
#endif
// #endif

// #if 0
static int	checking_cmd(char *cmd)
{
	char 	*tmp;
	size_t	i;

	i = -1;
	tmp = cmd;
	while (tmp[++i])
	{
		if (ft_isalpha(tmp[i]))
		{
			if (tmp[i] >= 'A' && tmp[i] <= 'Z')
				tmp[i] += 32;
		}
	}
	if (tmp[i])
		return (-1);
	return (checking_cmd_for_tocken(tmp));
}

static void init_cmd(t_commands *cmd)
{
	cmd->cmd = cmd->lst->content;
	cmd->invalid = checking_cmd(cmd->cmd);
	cmd->num_cmd = cmd->invalid > 0 ? cmd->invalid : 0;
}

static void	init_arg(t_commands *cmd)
{
	t_list	*tmp;

	tmp = cmd->lst->next;
	free(cmd->lst);
	cmd->lst = tmp;


}
// #endif
static void	add_list(t_list **lst, char **line, size_t size)
{
	t_list	*new_list;
	char	*new_line;

	new_line = ft_strndup(*line, size);
	new_list = ft_lstnew(new_line);
	ft_lstadd_back(lst, new_list);
	*line += size;
	*line = skip_spaces(*line);
}

void		creat_lst(t_commands *cmd, t_data *data, char *line)
{
	char	*p_s;
	
	(void)data;
	if (!(*line))
		error_output(NULL, NULL);
	while (*line)
	{
		if ((p_s = ft_strchr2(line, SPECSYMBOL)))
		{
			if (*p_s == ' ')
				add_list(&cmd->lst, &line, p_s - line);
			else if (*p_s == '\'')
				add_list(&cmd->lst, &line, move_pointer(cmd, data, p_s, line));
			else if (*p_s == '\"')
				add_list(&cmd->lst, &line, move_pointer(cmd, data, p_s, line));
		}
		else
			add_list(&cmd->lst, &line, ft_strlen(line));
	}
}

size_t		find_end_of_command(char *line)
{
	char	*p;
	
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


void		data_collection(t_commands **cmd, t_data *data, char **line)
{
	size_t	len_cmd;
	char	*command;

	*line = skip_spaces(*line);
	len_cmd = find_end_of_command(*line);
	command = ft_strndup(*line, len_cmd);
	creat_lst(*cmd, data, command);
	*line += len_cmd;
	init_cmd(*cmd);
	init_arg(*cmd);
	(*cmd)->count_args = ft_lstsize((*cmd)->lst);
	ft_free_tmp(command);

}

t_commands		*create_list(t_data *data, char *line)
{
	char		*p;
	t_commands 	*cmd;
	t_commands	*tmp;

	p = line;
	cmd = init_struct_commands();
	tmp = cmd;
	while (*p)
	{
		data_collection(&tmp, data, &p);
		add_node(tmp, data, &p);
	}
	return (cmd);
}
