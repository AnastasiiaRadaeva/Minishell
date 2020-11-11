/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/11 13:00:06 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//anatashi
static void	add_list(t_list **lst, char *line, size_t size)
{
	t_list	*new_list;
	char	*new_line;

	new_line = ft_strndup(line, size);
	new_list = ft_lstnew(new_line);
	ft_lstadd_back(lst, new_list); 
}

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

// #if 0
	t_list *tmp;
	tmp = cmd->lst;

	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}

// #endif
}

#if 0
static void split_string_into_arguments(t_commands *cmd, char *new_line)
{
	char 	*p_s;
	static	char	*p_w;
	t_list	*lst;

	lst = NULL;
	while ((p_w = (p_s = ft_strchr2(new_line, SPECSYMBOL)) ? move_pointer(p_w, p_s) : NULL))
	{
		if (*p_s == '\'')
			add_list(&lst, p_s, p_w - p_s);
		else if (*p_s == ' ')
			add_list(&lst, new_line, p_s - new_line);
		new_line += p_w - new_line;
	}
	if (*new_line)
		add_list(&lst, new_line, ft_strlen(new_line));
	if (!(cmd->arg = create_two_dimensional_array_from_lst(lst)))
		error_output(cmd, MALLOC_9);
	ft_free_tmp(lst);

#if 0
	size_t i = -1;

	while (++i < ft_strlenarr(cmd->arg))
		ft_putendl(cmd->arg[i]);

#endif

#if 0
	t_list *tmp;
	tmp = lst;

	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}

#endif
}

#endif

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

static void	remove_spaces_in_string(t_commands *cmd, char **old_line, 
									char **new_line)
{
	if (!(*new_line = ft_strtrim(*old_line, WHITESPACES)))
		error_output(cmd, MALLOC_2);
	ft_free_tmp(*old_line);
}

static int	checking_cmd(char **cmd)
{
	char 	*tmp;
	size_t	i;

	i = -1;
	tmp = *cmd;
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

void	create_args(t_commands *cmd, char **line, char **new_line)
{
	init_struct_commands(&cmd);
	remove_spaces_in_string(cmd, line, new_line);
	*new_line = ft_strndup2(new_line, find_end_cmd(*new_line, SEPARATORS)
													- **new_line);
	split_string_into_arguments(cmd, *new_line);
	init_cmd(cmd);
	init_arg(cmd);
	
	/*
	** debug content cmd->cmd and cmd->lst;
	*/
	#if 0
		ft_putendl(cmd->cmd);
		for (t_list *tmp = cmd->lst; (tmp); tmp = tmp->next)
			ft_putendl(tmp->content);
	#endif
}







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

void	create_list(t_commands **cmd, char *line, char **new_line)
{
	// init_struct_commands(cmd);
	remove_spaces_in_string(cmd, line, new_line);
	ft_free_tmp(line);
	ft_divider_line(cmd, new_line);
	// return (cmd);
}
