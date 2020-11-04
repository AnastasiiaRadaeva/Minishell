/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/04 16:16:16 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_skip_spases(char *line, char flag)
{
	int index;

	if (flag == 's')
	{
		index = 0;
		while (ft_isspace(line[index]) == 1)
			index++;
	}
	if (flag == 'e')
	{
		index = ft_strlen(line) - 1;
		while (ft_isspace(line[index]) == 1)
			index--;
	}
	return (index);	
}

static char	*ft_comand_line(char *old_line)
{
	int		index;
	char	*new_line;

	index = ft_skip_spases(old_line, 's');
	old_line += index;
	index = ft_skip_spases(old_line, 'e');
	if (!(new_line = ft_strndup(old_line, index + 1)))
		return (NULL);
	return (new_line);
}

t_commands	*creat_list(t_commands *cmd, char *line)
{
	char *line_new; 

	if (!(line_new = ft_comand_line(*line)))
		error_output(cmd, MALLOC_2);
	free(line);
	// ft_spec_symb
	return (line_new);
}