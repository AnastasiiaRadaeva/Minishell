/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:58:06 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/20 20:00:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void		give_pwd(t_commands *cmd, t_data *data)
{
	char	tmp[1024];

	if (getcwd(tmp, 1000) == NULL)
		error_output(cmd, data, PWD_GETCWD);
	getcwd(tmp, 1024);
	ft_putendl(tmp);
}
