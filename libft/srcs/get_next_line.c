/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:09:44 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/21 12:22:36 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	lsterr(t_gnl **head, t_gnl **tmp, char **remaind, char **line)
{
	t_gnl		*p_tmp;

	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*remaind)
	{
		free(*remaind);
		*remaind = NULL;
	}
	if (*head == *tmp)
		*head = (*head)->next;
	else
	{
		p_tmp = *head;
		while (p_tmp->next != *tmp)
			p_tmp = p_tmp->next;
		p_tmp->next = (*tmp)->next;
	}
	free(*tmp);
}

static	void	clear_list(t_gnl **head, t_gnl **tmp, char **remaind)
{
	t_gnl			*p_tmp;

	if (*remaind)
	{
		free(*remaind);
		*remaind = NULL;
	}
	if (*head == *tmp)
		*head = (*head)->next;
	else
	{
		p_tmp = *head;
		while (p_tmp->next != *tmp)
			p_tmp = p_tmp->next;
		p_tmp->next = (*tmp)->next;
	}
	free(*tmp);
}

static int		checking_of_remaind(t_gnl *tmp, char **line)
{
	char			*tmp_p;
	char			*end_l;

	if (tmp->remaind)
		if ((end_l = ft_strchr(tmp->remaind, '\n')))
		{
			*end_l = '\0';
			if (!(*line = ft_strdup_gnl(tmp->remaind)))
				return (-1);
			tmp_p = tmp->remaind;
			if (!(tmp->remaind = ft_strdup_gnl(++end_l)))
				return (-1);
			free(tmp_p);
		}
		else
		{
			if (!(*line = ft_strdup_gnl(tmp->remaind)))
				return (-1);
			free(tmp->remaind);
			tmp->remaind = NULL;
		}
	else if (!(*line = ft_strdup_gnl("")))
		return (-1);
	return (0);
}

static int		get_line(t_gnl *tmp, char **line, char *buf)
{
	long long		ret;
	char			*end_l;

	ret = 0;
	if ((checking_of_remaind(tmp, line)) == -1)
		return (-1);
	while (!(tmp->remaind) && (ret = read(tmp->fd, buf, BUFFER_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if ((end_l = ft_strchr(buf, '\n')))
		{
			*end_l = '\0';
			if (!(tmp->remaind = ft_strdup_gnl(++end_l)))
				return (-1);
		}
		if (!(*line = ft_strjoin_gnl(line, buf)))
			return (-1);
	}
	free(buf);
	return ((ret || tmp->remaind) ? 1 : 0);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;
	char			*buf;
	int				gnl;

	if (fd < 0 || !line || (BUFFER_SIZE < 1))
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (head == NULL)
		if (!(head = read_new_fd(fd)))
			return (-1);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			if (!(tmp->next = read_new_fd(fd)))
				return (-1);
		tmp = tmp->next;
	}
	if ((gnl = get_line(tmp, line, buf)) == 0)
		clear_list(&head, &tmp, &tmp->remaind);
	if (gnl == -1)
		lsterr(&head, &tmp, &tmp->remaind, line);
	return (gnl);
}
