/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:42:23 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/21 12:41:09 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFFER_SIZE 4096

typedef struct		s_gnl
{
	int				fd;
	char			*remaind;
	struct s_gnl	*next;
}					t_gnl;

t_gnl				*read_new_fd(int fd);
char				*ft_strjoin_gnl(char **s1, char *s2);
char				*ft_strdup_gnl(char *src);
#endif
