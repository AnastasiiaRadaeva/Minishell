/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:50:50 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/21 12:35:12 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*read_new_fd(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->remaind = NULL;
	new->next = NULL;
	return (new);
}

char		*ft_strdup_gnl(char *src)
{
	char	*new_array;
	size_t	i;

	i = 0;
	if (!(new_array = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (src[i])
	{
		new_array[i] = src[i];
		i++;
	}
	new_array[i] = '\0';
	return (new_array);
}

char		*ft_strjoin_gnl(char **s1, char *s2)
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
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	free(*s1);
	return (new_str);
}
