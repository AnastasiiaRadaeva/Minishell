/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_cmd_for_tocken.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:25:17 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/10 19:32:09 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#if 0
int			return_tochen_number(char *word)
{
	if (!(ft_strcmp("echo", word)))
		return (1);
	else if (!(ft_strcmp("cd", word)))
		return (2);
	else if (!(ft_strcmp("pwd", word)))
		return (3);
	else if (!(ft_strcmp("export", word)))
		return (4);
	else if (!(ft_strcmp("unset", word)))
		return (5);
	else if (!(ft_strcmp("env", word)))
		return (6);
	else if (!(ft_strcmp("exit", word)))
		return (7);
}
#endif

int			checking_cmd_for_tocken(char *word)
{
	if (!(ft_strcmp("echo", word)))
		return (1);
	else if (!(ft_strcmp("cd", word)))
		return (2);
	else if (!(ft_strcmp("pwd", word)))
		return (3);
	else if (!(ft_strcmp("export", word)))
		return (4);
	else if (!(ft_strcmp("unset", word)))
		return (5);
	else if (!(ft_strcmp("env", word)))
		return (6);
	else if (!(ft_strcmp("exit", word)))
		return (7);
	return (-1);
}
