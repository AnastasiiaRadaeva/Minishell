/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:42:00 by anatashi          #+#    #+#             */
/*   Updated: 2020/11/12 14:50:01 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lensplit(char const *s, int c)
{
	int		cword;
	int		cles;

	cword = 0;
	cles = 0;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s == c)
			cles = 0;
		else if (cles == 0)
		{
			cles = 1;
			cword++;
		}
		s++;
	}
	return (cword);
}

static	int	ft_lenword(char const *s, int i, int c)
{
	int		lenw;

	lenw = 0;
	while (s[i] != c && s[i])
	{
		lenw++;
		i++;
	}
	return (lenw);
}

static char	**ft_freearrpnt(char **nstr, size_t j)
{
	while (j--)
		free(nstr[j]);
	free(nstr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**nstr;
	int		lens;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	lens = ft_lensplit(s, c);
	if (!(nstr = (char **)malloc(sizeof(char *) * (lens + 1))))
		return (NULL);
	while (lens)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(nstr[j] = ft_substr(s, i, ft_lenword(s, i, c))))
			return (ft_freearrpnt(nstr, j));
		i += ft_lenword(s, i, c);
		j++;
		lens--;
	}
	nstr[j] = NULL;
	return (nstr);
}