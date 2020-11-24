/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 15:53:02 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/14 16:07:08 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		*if_dollar(t_data *data, char *line, int *invalid)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(line[i]) || line[i] == '_')
		i++;
}