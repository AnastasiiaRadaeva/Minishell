/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:03:58 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/03 14:16:31 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_input(char **line, t_data *data)
{
	int		gnl;
	char	*baff;
	char	*tmp;

	gnl = 0;
	baff = ft_strdup("");
	while (gnl != 1)
	{
		if ((gnl = get_next_line(0, line)) < 0)
			error_output(NULL, data, GNL_1);
		if (gnl == 0 && *line[0] != '\0')
		{
			tmp = baff;
			baff = ft_strjoin(baff, *line);
			free(tmp);
		}
		if (gnl == 0 && *line[0] == '\0' && *baff == '\0')
			exit(EXIT_SUCCESS);
	}
	tmp = *line;
	*line = ft_strjoin(baff, *line);
	free(tmp);
	free(baff);
}

void		read_cmd(t_data *data, char **line)
{
	get_input(line, data);
	// if (get_next_line(0, line) < 0)
	// 	error_output(NULL, data, GNL_1);
	if (ft_strlen(*line) == 4 && ft_strncmp("exit", *line, 4) == 0)
	{
		ft_free_tmp(*line);
		program_exit(NULL, data, 1);
	}
}
