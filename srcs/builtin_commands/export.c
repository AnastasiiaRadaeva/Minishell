/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/11/18 11:58:05 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	ft_export(t_commands *cmd, t_data *all)
{
	char	**temp_env;
	int		index;
	t_list	*temp_list;

	index = -1;
	temp_list = cmd->lst;
	check_args_for_validity(all, cmd); //функция должна проверить на валидность аргументы и перезаписать их нужным образом
	all->count_str += cmd->count_args;
	temp_env = all->envp;
	if (!(all->envp = (char **)malloc(sizeof(char *) * all->count_str)))
		error_output(cmd, MALLOC_12);
	while (++index < all->env_var)
		all->envp[index] = temp_env[index];
	while (index < all->count_str - 1)
	{
		all->envp[index] = temp_list->content;
		temp_list = temp_list->next;
		index++;
	}
	all->envp[index] = temp_env[all->env_var];
	all->env_var = index;
	all->envp[++index] = NULL;
	free(temp_env);
}