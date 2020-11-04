/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_add_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 14:45:36 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/12 09:18:57 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_add_char(char *str, size_t count, int ch)
{
	char	*new_str;
	size_t	j;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	j = ft_strlen(str) + count + 1;
	if (!(new_str = (char *)malloc(j * sizeof(char))))
		return (NULL);
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	while (c != count)
	{
		new_str[j++] = ch;
		c++;
	}
	new_str[j] = '\0';
	return (new_str);
}
