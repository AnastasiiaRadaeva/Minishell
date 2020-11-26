
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:12:41 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/23 18:39:32 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#if 0
char	*ft_pwd(t_commands *cmd, t_data *all)
{
	if (!(all->envp[all->current_pwd]))
		error_output(cmd, all, PWD_GETCWD); // ошибку getcwd переписать 
	return (all->envp[all->current_pwd] + 4);
}
#endif

void	ft_pwd(t_commands *cmd, t_data *all)
{
	if (!(all->envp[all->current_pwd]))
		error_output(cmd, all, PWD_GETCWD); // эту ошибку переписать
	ft_putendl(all->envp[all->current_pwd] + 4);
}