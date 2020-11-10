/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:20:39 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/10 17:01:51 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

char	**ft_env(t_commands *cmd, t_data *all)
{
	int	len;
	int	i;

	i = 3;
	len = ft_strlen(all->envp[all->env_var]);
	while (--i >= 0 && --len >= 0)
		all->envp[all->env_var][len] = cmd->cmd[i];
	return (all->envp[all->env_var]);
}
