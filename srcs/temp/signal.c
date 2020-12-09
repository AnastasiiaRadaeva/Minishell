/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:58:40 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 13:11:57 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int num)
{
	if (num == SIGINT)
	{
		ft_putendl("\b\b  \b\b");
		global_status = 1;
		print_promt_string();
	}
	if (num == SIGQUIT)
	{
		ft_putstr("\b\b  \b\b");
		global_status = 0;
	}
}

void	signal_handler_2(int num)
{
	if (num == SIGINT)
	{
		ft_putstr("\n");
	}
	if (num == SIGQUIT)
		ft_putstr("Quit: 3\n");
}