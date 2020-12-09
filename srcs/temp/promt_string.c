/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   promt_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:03:31 by anatashi          #+#    #+#             */
/*   Updated: 2020/12/09 13:57:34 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_promt_string(void)
{
	ft_putstr_fd("\033[1;34m", 1);
	ft_putstr_fd("minishell$ ", 1);
	ft_putstr_fd("\x1B[0m", 1);
}
