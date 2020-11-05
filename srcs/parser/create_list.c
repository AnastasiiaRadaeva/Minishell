/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:29:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/05 14:51:37 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#if 0
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


static void	ft_comand_line(t_commands *cmd, char *old_line, char **new_line)
{
	int		index;

	index = ft_skip_spases(old_line, 's');
	old_line += index;
	index = ft_skip_spases(old_line, 'e');
	if (!(*new_line = ft_strndup(old_line, index + 1)))
		error_output(cmd, MALLOC_2);
}
#endif

static void	ft_skip_spases(char *line, int	*index)
{
	while (ft_isspace(line[*index]))
		++(*index);
}

static void	ft_comand_line(t_commands *cmd, char *old_line, char **new_line)
{
	int		index;

	ft_skip_spases(old_line, &index);
	if (!(*new_line = ft_strdup(old_line + index)))
		error_output(cmd, MALLOC_2);
}


void	create_list(t_commands *cmd, char *line, char **new_line)
{
	init_struct_commands(cmd);
	ft_comand_line(cmd, line, new_line);
	ft_free_tmp(line);
	// ft_spec_symb
	// return (cmd);
}