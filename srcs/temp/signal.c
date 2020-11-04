/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:58:40 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/04 12:19:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int num)
{
	if (num == SIGINT)
	{
		ft_putstr("\n");
		print_promt_string();
		signal(SIGINT, signal_handler);
	}
}
