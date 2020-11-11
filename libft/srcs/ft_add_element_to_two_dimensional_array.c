/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_element_to_two_dimensional_array.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:30:03 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/09 15:23:23 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**creat_new_two_dimensionall_array(char *elem)
{
	char	**new_array;

	if (!(new_array = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	new_array[0] = elem;
	new_array[1] = NULL;
	return (new_array);

}

char		**ft_add_element_to_two_dimensional_array(char **array, char *elem)
{
	size_t	i;
	size_t	len;
	char	**new_array;
	
	i = -1;
	if (!array)
		return (new_array = creat_new_two_dimensionall_array(elem));
	len = ft_strlenarr(array);
	if (!(new_array = (char **)malloc(sizeof(char *) * (len + 2))))
		return (NULL);
	while (++i < len)
		new_array[i] = array[i];
	new_array[i] = elem;
	new_array[++i] = NULL;
	ft_free_tmp(*array);
	return (new_array);
}
