/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:04:43 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/02 20:08:18 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	*fill_it(int *tab)
{
	int *no;

	if (!(no = (int *)malloc(sizeof(int *) * 7)))
		return (0);
	no[0] = ft_abs(tab[2] - tab[0]);
	no[1] = tab[0] < tab[2] ? 1 : -1;
	no[2] = ft_abs(tab[3] - tab[1]);
	no[3] = tab[1] < tab[3] ? 1 : -1;
	no[4] = (no[0] > no[2] ? no[0] : -no[2]) / 2;
	no[5] = 0;
	no[6] = 0;
	return (no);
}

int	drawline(int *tab, t_env *e, t_coo *current, t_coo *current2)
{
	int *no;

	no = fill_it(tab);
	while (42)
	{
		no[6] = no[6] + 10;
		if (current->z != 0 || current2->z != 0)
			mlx_pixel_put(e->mlx, e->win, tab[0], tab[1], no[6] * 255 * e->rgb);
		else
			mlx_pixel_put(e->mlx, e->win, tab[0], tab[1], 30 * 55 * 35);
		if (tab[0] == tab[2] && tab[1] == tab[3])
			break ;
		no[5] = no[4];
		if (no[5] > -no[0])
		{
			no[4] -= no[2];
			tab[0] += no[1];
		}
		if (no[5] < no[2])
		{
			no[4] += no[0];
			tab[1] += no[3];
		}
	}
	return (0);
}

int	draw_map_x(t_env *e)
{
	t_coo	*current;
	t_coo	*current2;
	int		*tab;

	current = *(e->head);
	current2 = (*(e->head))->next;
	while (current->next)
	{
		tab = get_transfo(e, current, current2);
		if (current->y == current2->y)
			drawline(tab, e, current, current2);
		(current) = (current)->next;
		(current2) = (current2)->next;
	}
	return (0);
}

int	draw_map_y(t_env *e)
{
	t_coo	*current;
	t_coo	*current2;
	int		y_org;
	int		*tab;

	current = *(e->head);
	y_org = current->y;
	current2 = (*(e->head))->next;
	while (current2->y == y_org)
		current2 = current2->next;
	while (current2)
	{
		tab = get_transfo(e, current, current2);
		if (current->x == current2->x)
			drawline(tab, e, current, current2);
		(current) = (current)->next;
		(current2) = (current2)->next;
	}
	return (0);
}
