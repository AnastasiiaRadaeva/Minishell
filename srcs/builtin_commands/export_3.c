/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:04:43 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/10 11:15:17 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_char_2(char *str, char symb)
{
	int	i;

	i = 0;
	while (str[i] != symb && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}

static void	record_end_of_array(char ***new_env, int i, t_data **all)
{
	while ((*new_env)[++i])
		(*all)->envp[i] = (*new_env)[i];
	(*all)->envp[i] = NULL;
	free(*new_env);
}

static int	change(t_data **all, t_list **tmp_lst, t_commands **cmd,\
														int *num_of_lst)
{
	int		index;
	char	**new_env;
	int		i;

	index = -1;
	while ((*all)->envp[++index])
		if (ft_strncmp((char *)(*tmp_lst)->content, (*all)->envp[index],\
						find_char_2((*all)->envp[index], '=') + 1) == 0)
		{
			new_env = (*all)->envp;
			if (!((*all)->envp = (char **)malloc(sizeof(char *) *\
											(*all)->count_str + 1)))
				error_output(*cmd, *all, MALLOC_11);
			i = -1;
			while (++i < index)
				(*all)->envp[i] = new_env[i];
			if (!((*all)->envp[i] = ft_strdup((char *)(*tmp_lst)->content)))
				error_output(*cmd, *all, MALLOC_11);
			free(new_env[i]);
			record_end_of_array(&new_env, i, all);
			delete_lst(cmd, tmp_lst, *num_of_lst, 0);
			return (1);
		}
	return (0);
}

void		change_var(t_data **all, t_commands **cmd, int num_of_lst)
{
	t_list	*tmp_lst;
	int		error;

	tmp_lst = (*cmd)->lst;
	while (tmp_lst)
	{
		error = change(all, &tmp_lst, cmd, &num_of_lst);
		if (error == 0)
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}
