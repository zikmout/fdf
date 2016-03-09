/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:01:28 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/02 20:11:21 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env		*init_struct(void)
{
	t_env	*e;
	t_coo	*begin;

	e = NULL;
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(begin = (t_coo *)malloc(sizeof(t_coo))))
		return (NULL);
	e->mlx = NULL;
	e->win = NULL;
	e->pad = 20;
	e->x2d = 0;
	e->y2d = 0;
	e->rgb = 1;
	e->rot = 0;
	return (e);
}

t_coo		*ft_list_find_end(t_coo *list)
{
	if (list->next == NULL)
		return (list);
	return (ft_list_find_end(list->next));
}

void		ft_list_push_back(t_coo **begin_list, int x, int y, int z)
{
	t_coo	*new_node;

	new_node = ft_create_elem(x, y, z);
	if (*begin_list == NULL)
		*begin_list = new_node;
	else
		ft_list_find_end(*begin_list)->next = new_node;
}

t_coo		*ft_create_elem(int x, int y, int z)
{
	t_coo	*node;

	if (!(node = (t_coo *)malloc(sizeof(t_coo))))
		return (NULL);
	node->x = x;
	node->y = y;
	node->z = z;
	node->next = NULL;
	return (node);
}

int			ft_abs(int diff)
{
	if (diff < 0)
		return (-diff);
	return (diff);
}
