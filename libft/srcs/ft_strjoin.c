/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 17:58:22 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/21 10:51:13 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*nstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(nstr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	ft_strlcpy(nstr, s1, lens1 + 1);
	ft_strlcat(nstr, s2, lens1 + lens2 + 1);
	return (nstr);
}
