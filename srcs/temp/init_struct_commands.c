/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:32:10 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/11 11:38:49 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_struct_commands(t_commands **cmd)
{
	if (!(*cmd = (t_commands *)ft_calloc(sizeof(t_commands), 1)))
		error_output(*cmd, MALLOC_1);
}
