/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 19:59:41 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/05 20:07:19 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 2)
		e->rot = e->rot - 1;
	if (button == 1)
		e->rot = e->rot + 1;
	mlx_clear_window(e->mlx, e->win);
	expose_hook(e);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	int	xp;
	int	yp;
	int	zp;

	xp = 1;
	yp = 1;
	zp = 0;
	if (keycode == 53 || keycode == 4 || keycode == 69 || keycode == 78 ||
			keycode == 8 || keycode == 6 || keycode == 7 ||
			keycode == 83 || keycode == 84)
		ft_arrows(e, keycode);
	if (keycode == 124 || keycode == 125)
	{
		yp = (keycode == 124) ? (-1) : (yp);
		yp = (keycode == 125) ? (1) : (yp);
		get_move(e, xp, yp, zp);
	}
	else if (keycode == 126)
		get_move(e, -xp, -yp, zp);
	else if (keycode == 123)
		get_move(e, -xp, yp, zp);
	mlx_clear_window(e->mlx, e->win);
	expose_hook(e);
	return (0);
}

int	expose_hook(t_env *e)
{
	draw_map_x(e);
	draw_map_y(e);
	return (0);
}

int	launch_win(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		ft_putstr("Keyboard pb !!\n");
	if ((e->win = mlx_new_window(e->mlx, 1200, 1200, "/!\\ fdf /!\\")) == NULL)
		ft_putstr("Window pb !!\n");
	expose_hook(e);
	mlx_hook(e->win, 2, 0, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
