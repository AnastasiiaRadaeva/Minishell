/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:58:40 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/27 17:46:46 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int num)
{
	// if (num == SIGINT)
	// {
	// 	ft_putstr("\n");
	// 	print_promt_string();
	// 	signal(SIGINT, signal_handler);
	// }
	if (num == SIGINT)
	{
		ft_putendl("\b\b  ");
		print_promt_string();
	}
	if (num == SIGQUIT)
		ft_putstr("\b\b  \b\b");
}
