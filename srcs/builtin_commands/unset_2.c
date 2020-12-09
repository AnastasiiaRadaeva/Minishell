/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:12:22 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/12/09 14:30:54 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_with_status(t_list **lst_for_del)
{
	error_case("minishell: unset: `", (*lst_for_del)->content, \
					"': not a valid identifier\n");
	g_global_status = 1;
}

static void	del_next_lst(t_list **new_lst, int *error, int *num_of_lst,\
														t_list **lst_for_del)
{
	while ((*new_lst))
	{
		if (*error == *num_of_lst - 1)
		{
			(*new_lst)->next = (*lst_for_del)->next;
			(*lst_for_del) = (*new_lst)->next;
		}
		(*new_lst) = (*new_lst)->next;
		(*error)++;
	}
}

int			del_lst(t_commands **cmd, t_list **lst_for_del, int num_of_lst,\
																	int error)
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	if (error == 1)
		error_with_status(lst_for_del);
	tmp_lst = (*lst_for_del);
	new_lst = (*cmd)->lst;
	error = 0;
	if (num_of_lst == 0)
	{
		(*lst_for_del) = new_lst->next;
		(*cmd)->lst = new_lst->next;
	}
	else
		del_next_lst(&new_lst, &error, &num_of_lst, lst_for_del);
	(*cmd)->count_args--;
	free(tmp_lst);
	return (1);
}
