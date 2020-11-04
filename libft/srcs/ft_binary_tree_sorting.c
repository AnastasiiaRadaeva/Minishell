/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree_sorting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anatashi <anatashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:42:27 by anatashi          #+#    #+#             */
/*   Updated: 2020/10/12 09:22:41 by anatashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_tree	*ft_creat_tree(double x, t_tree *tree)
{
	if (!(tree = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	tree->num = x;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

static void		freemem(t_tree *tree)
{
	if (tree != NULL)
	{
		freemem(tree->left);
		freemem(tree->right);
		free(tree);
		tree = NULL;
	}
}

static t_tree	*ft_addnode(double x, t_tree *tree)
{
	if (tree == NULL)
	{
		if (!(tree = ft_creat_tree(x, tree)))
			return (NULL);
	}
	else
	{
		if (x < tree->num)
		{
			if (!(tree->left = ft_addnode(x, tree->left)))
				return (NULL);
		}
		else
		{
			if (!(tree->right = ft_addnode(x, tree->right)))
				return (NULL);
		}
		return (tree);
	}
	return (tree);
}

static double	creat_sort_arr(double *x, int *i, t_tree *tree)
{
	if (tree)
	{
		creat_sort_arr(x, i, tree->left);
		x[(*i)++] = (tree->num);
		creat_sort_arr(x, i, tree->right);
	}
	return (*x);
}

double			*ft_binary_tree_sorting(double *x, int in)
{
	t_tree	*tree;
	int		i;

	tree = NULL;
	i = -1;
	while (++i < in)
	{
		if (!(tree = ft_addnode(x[i], tree)))
		{
			freemem(tree);
			return (x);
		}
	}
	i = 0;
	*x = creat_sort_arr(x, &i, tree);
	free(tree);
	return (x);
}
