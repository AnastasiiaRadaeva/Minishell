/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 10:41:05 by anatashi          #+#    #+#             */
/*   Updated: 2020/08/22 09:40:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjnoin(char **s1, char *s2, size_t size)
{
	char	*new_str;
	size_t	j;
	size_t	i;

	if (!*s1 || !s2)
		return (NULL);
	i = 0;
	j = ft_strlen(*s1) + ft_strlen(s2) + 1;
	if (!(new_str = (char *)malloc(j * sizeof(char))))
		return (NULL);
	j = 0;
	while ((*s1)[i])
		new_str[j++] = (*s1)[i++];
	i = 0;
	while (s2[i] && size-- != 0)
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(*s1);
	return (new_str);
}
