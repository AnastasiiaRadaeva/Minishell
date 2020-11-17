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