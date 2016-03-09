/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:00:16 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 16:11:46 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_arrows(t_env *e, int keycode)
{
	if (keycode == 69)
		e->pad = e->pad + 1;
	if (keycode == 78)
		e->pad = e->pad - 1;
	if (keycode == 8)
		e->rgb += 1;
	if (keycode == 6)
		get_move(e, 0, 0, 1);
	if (keycode == 7)
		get_move(e, 0, 0, -1);
	if (keycode == 83)
		e->rot = e->rot - 1;
	if (keycode == 84)
		e->rot = e->rot + 1;
	if (keycode == 4)
		ft_menu(e);
	if (keycode == 53)
		exit(0);
	return (0);
}

int			*get_transfo(t_env *e, t_coo *current, t_coo *current2)
{
	int		*tab;
	double	q;

	q = rad_to_deg(e->rot);
	if (!(tab = (int *)malloc(sizeof(tab) * 4)))
		return (NULL);
	tab[0] = e->pad * e->x2d + e->pad * 0.71 * (current->x - current->y);
	tab[1] = e->pad * e->y2d + e->pad * 0.41 * (current->y + current->x)
		- e->pad * 0.82 * current->z;
	tab[2] = e->pad * e->x2d + e->pad * 0.71 * (current2->x - current2->y);
	tab[3] = e->pad * e->y2d + e->pad * 0.41 * (current2->y + current2->x)
		- e->pad * 0.82 * current2->z;
	if (e->rot != 0)
	{
		tab[0] = tab[0] * cos(q) - tab[1] * sin(q);
		tab[1] = tab[0] * sin(q) + tab[1] * cos(q);
		tab[2] = tab[2] * cos(q) - tab[3] * sin(q);
		tab[3] = tab[2] * sin(q) + tab[3] * cos(q);
	}
	return (tab);
}

void		ft_menu(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xff0f0f,\
			"/!\\ ...CONTROLS.. /!\\");
	mlx_string_put(e->mlx, e->win, 10, 50, 0x0fff0f,\
			"---> +/- ==> Zoom in / Zoom out");
	mlx_string_put(e->mlx, e->win, 10, 90, 0x0fff0f,\
			"---> 1/2 or mouse left/mouse right ==> Rotate Map");
	mlx_string_put(e->mlx, e->win, 10, 130, 0x0fff0f,\
			"---> Up/Down/Left/Right arrows ==> Move Map");
	mlx_string_put(e->mlx, e->win, 10, 170, 0x0fff0f,\
			"---> Z/X Keys ==> Increase/Decrease z coordinate");
	mlx_string_put(e->mlx, e->win, 10, 210, 0x0fff0f,\
			"---> C ==> Change the shading");
	mlx_string_put(e->mlx, e->win, 10, 250, 0x0fff0f,\
			"---> Esc ==> Exit the program");
	mlx_string_put(e->mlx, e->win, 10, 290, 0x0fff0f,\
			"---> H ==> Help");
	mlx_string_put(e->mlx, e->win, 10, 600, 0x0fffff,\
			"- PRESS any key to exit...!");
	mlx_loop(e->mlx);
}

void		get_move(t_env *e, int xp, int yp, int zp)
{
	t_coo	*current;

	current = *(e->head);
	while (current)
	{
		current->x = current->x + xp;
		current->y = current->y + yp;
		if (current->z != 0 && zp != 0)
			current->z = current->z + zp;
		current = current->next;
	}
}
