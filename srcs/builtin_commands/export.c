/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:22:37 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/04 11:49:05 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_with_status(t_list **lst)
{
	error_case("minishell: export: `", (*lst)->content,\
								"': not a valid identifier\n");
	global_status = 1;
}

static void	ft_env_for_export(t_commands *cmd, t_data *all, char **new)
{
	int		i;
	char	*string;
	char	*temp_str;

	if (!(string = ft_strdup("")))
		error_output(cmd,  all, "malloc: ft_env");
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

static void	empty_export(t_data **all, t_commands **cmd)
{
	int		i;
	int		index;
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
		flag_2 = 1;
		tmp = new;
		index = 0;
		i = 0;
		if (!(new = (char **)malloc(sizeof(char *) * ((*all)->count_str + 1))))
			error_output(*cmd, *all, MALLOC_12);
		new[i] = tmp[index];
		while (tmp[++index])
		{
			if (ft_strcmp(new[i], tmp[index]) > 0)
			{
				new[i + 1] = new[i];
				new[i++] = tmp[index];
				flag_2 = 0;
			}
			else
				new[++i] = tmp[index];
		}
		new[++i] = NULL;
		free(tmp);
		tmp = NULL;
	}
	ft_env_for_export(*cmd, *all, new);
	free(new);
}

static int delete_lst(t_commands **cmd, t_list **lst, int num_of_l, int error)
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (error == 1)
		error_with_status(lst);
	tmp_lst = (*lst);
	new_lst = (*cmd)->lst;
	error = -1;
	if (num_of_l == 0)
	{
		(*lst) = new_lst->next;
		(*cmd)->lst = new_lst->next;
	}
	else
	{
		while (new_lst && ++error != num_of_l - 1)
			new_lst = new_lst->next;
		new_lst->next = (*lst)->next;
		(*lst) = new_lst->next;
	}
	(*cmd)->count_args--;
	free(tmp_lst);
	return (1);
}

static int	find_char(char *str, char symb)
{
	int	i;

	i = 0;
	while (str[i] != symb && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
}

static void	change_var(t_data **all, t_commands **cmd, int num_of_lst, int i)
{
	t_list	*tmp_lst;
	char 	**new_env;
	int 	index;
	int		error;

	tmp_lst = (*cmd)->lst;
	while (tmp_lst)
	{
		error = 0;
		index = -1;
		while ((*all)->envp[++index])
		{

			if (ft_strncmp((char *)tmp_lst->content, (*all)->envp[index],\
							find_char((*all)->envp[index],'=') + 1) == 0)
			{
				new_env = (*all)->envp;
				if (!((*all)->envp = (char **)malloc(sizeof(char *) *\
												 (*all)->count_str + 1)))
					error_output(*cmd, *all, MALLOC_11);
				i = -1;
				while (++i < index)
					(*all)->envp[i] = new_env[i];
				if (!((*all)->envp[i] = ft_strdup((char *)tmp_lst->content)))
					error_output(*cmd, *all, MALLOC_11);
				free(new_env[i]);
				while (new_env[++i])
					(*all)->envp[i] = new_env[i];
				(*all)->envp[i] = NULL;
				free(new_env);
				error = delete_lst(cmd, &tmp_lst, num_of_lst, 0);
				break;
			}
		}
		if (error == 0)
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

static void	check_args_for_validity(t_commands **cmd)
{
	t_list	*tmp_lst;
	int		index;
	int		num_of_lst;
	int		error;

	tmp_lst = (*cmd)->lst;
	num_of_lst = 0;
	while (tmp_lst)
	{
		error = 0;
		if ((((char*)tmp_lst->content)[0]) == '_' || \
				ft_isalpha(((char*)tmp_lst->content)[0]) == 1)
		{
			index = 0;
			while (((char*)tmp_lst->content)[++index] != '=' && \
					((char*)tmp_lst->content)[index] != '\0')
			{
				if (((char*)tmp_lst->content)[index] != '_' && \
					ft_isalpha(((char*)tmp_lst->content)[index]) != 1 \
					&& ft_isalnum(((char*)tmp_lst->content)[index]) != 1)
				{
					error = delete_lst(cmd, &tmp_lst, num_of_lst, 1);
					break;
				}
			}
			if (error == 0 && tmp_lst && \
				((char*)tmp_lst->content)[index] == '\0')
				error = delete_lst(cmd, &tmp_lst, num_of_lst, 0);
		}
		else
			error = delete_lst(cmd, &tmp_lst, num_of_lst, 1);
		if (error == 0)
		{
			tmp_lst = tmp_lst->next;
			num_of_lst++;
		}
	}
}

void	ft_export(t_commands **cmd, t_data **all, int index)
{
	char	**temp_env;
	t_list	*temp_list;

	if ((*cmd)->lst)
	{
		check_args_for_validity(cmd);
		while (++index < (*cmd)->count_args)
			change_var(all, cmd, 0, 1);
		index = -1;
		(*all)->count_str += (*cmd)->count_args;
		temp_list = (*cmd)->lst;
		temp_env = (*all)->envp;
		if (!((*all)->envp = (char **)malloc(sizeof(char *) * \
								((*all)->count_str + 1))))
			error_output(*cmd, *all, MALLOC_12);
		while (temp_env[++index])
			(*all)->envp[index] = temp_env[index];
		while (index < (*all)->count_str)
		{
			(*all)->envp[index++] = ft_strdup(temp_list->content);
			temp_list = temp_list->next;
		}
		(*all)->envp[index] = NULL;
		free(temp_env);
	}
	else
		empty_export(all, cmd);
}
