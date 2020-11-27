/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:58:40 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/27 18:43:01 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int num)
{
	if (num == SIGINT)
	{
		ft_putendl("\b\b  ");
		print_promt_string();
	}
	if (num == SIGQUIT)
		ft_putstr("\b\b  \b\b");
}
