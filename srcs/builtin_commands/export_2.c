/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:11:33 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/07 12:47:36 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_with_status(t_list **lst)
{
	error_case("minishell: export: `", (*lst)->content,\
								"': not a valid identifier\n");
	global_status = 1;
}

int			delete_lst(t_commands **cmd, t_list **lst, int num_of_l, int error)
{
	t_list	*new_lst;
	// t_list	*tmp_lst;

	if (error == 1)
		error_with_status(lst);
	// tmp_lst = (*lst);
	new_lst = (*cmd)->lst;
	error = -1;
	if (num_of_l == 0)
	{
		(*lst) = new_lst->next;
		free((*cmd)->lst);
		(*cmd)->lst = NULL;
		(*cmd)->lst = (*lst);
	}
	else
	{
		while (new_lst && ++error != num_of_l - 1)
			new_lst = new_lst->next;
		new_lst->next = (*lst)->next;
		free((*lst));
		(*lst) = NULL;
		(*lst) = new_lst->next;
	}
	(*cmd)->count_args--;
	// free(tmp_lst);
	return (1);
}

static void	ft_env_for_export(t_commands *cmd, t_data *all, char **new)
{
	int		i;
	char	*string;
	char	*temp_str;

	if (!(string = ft_strdup("")))
		error_output(cmd, all, "malloc: ft_env");
	i = 0;
	while (new[i])
	{
		temp_str = string;
		if (!(string = ft_strjoin(string, "declare -x ")))
			error_output(cmd, all, "malloc: ft_env");
		free(temp_str);
		temp_str = string;
		if (!(string = ft_strjoin(string, new[i])))
			error_output(cmd, all, "malloc: ft_env");
		free(temp_str);
		temp_str = string;
		if (!(string = new[++i] ? ft_strjoin(string, "\n") : string))
			error_output(cmd, all, "malloc: ft_env");
		if (ft_strcmp(temp_str, string) != 0)
			free(temp_str);
	}
	ft_putendl(string);
}

static int	create_array_for_export(char ***new, t_commands **cmd, \
												t_data **all, char **tmp)
{
	int	index;
	int	i;
	int	flag;

	index = 0;
	i = 0;
	flag = 1;
	if (!((*new) = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
		error_output(*cmd, *all, MALLOC_12);
	(*new)[i] = tmp[index];
	while (tmp[++index])
	{
		if (ft_strcmp((*new)[i], tmp[index]) > 0)
		{
			(*new)[i + 1] = (*new)[i];
			(*new)[i++] = tmp[index];
			flag = 0;
		}
		else
			(*new)[++i] = tmp[index];
	}
	(*new)[++i] = NULL;
	return (flag);
}

void		empty_export(t_data **all, t_commands **cmd)
{
	int		i;
	int		flag_2;
	char	**tmp;
	char	**new;

	flag_2 = 0;
	i = -1;
	if (!(new = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
		error_output(*cmd, *all, MALLOC_12);
	while ((*all)->envp[++i])
		new[i] = (*all)->envp[i];
	new[i] = NULL;
	while (flag_2 == 0)
	{
		tmp = new;
		flag_2 = create_array_for_export(&new, cmd, all, tmp);
		free(tmp);
		tmp = NULL;
	}
	ft_env_for_export(*cmd, *all, new);
	free(new);
}
