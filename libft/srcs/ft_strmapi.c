/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 10:03:15 by anatashi          #+#    #+#             */
/*   Updated: 2020/05/24 12:12:19 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*nstr;
	size_t	i;
	size_t	slen;

	i = 0;
	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	if (!(nstr = (char *)malloc(sizeof(char) * slen + 1)))
		return (NULL);
	while (s[i])
	{
		nstr[i] = f(i, s[i]);
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
