/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:13:39 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/02 20:13:49 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_coo
{
	int		x;
	int		y;
	int		z;
	void	*next;
}				t_coo;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		pad;
	int		x2d;
	int		y2d;
	int		rgb;
	int		rot;
	t_coo	**head;
}				t_env;

int				mouse_hook(int button, int x, int y, t_env *e);
int				key_hook(int keycode, t_env *e);
int				expose_hook(t_env *e);
int				launch_win(t_env *e);
t_env			*init_struct(void);
t_coo			*ft_list_find_end(t_coo *list);
void			ft_list_push_back(t_coo **begin_list, int x, int y, int z);
t_coo			*ft_create_elem(int x, int y, int z);
int				ft_abs(int diff);
t_coo			*get_buffer(char **av, t_coo **begin);
t_coo			**get_map(char *str, t_coo **head, int y);
double			rad_to_deg(int deg);
int				draw_map_x(t_env *e);
int				draw_map_y(t_env *e);
int				drawline(int *tab, t_env *e, t_coo *current, t_coo *current2);
int				*fill_it(int *tab);
void			get_move(t_env *e, int xp, int yp, int zp);
int				*get_transfo(t_env *e, t_coo *current, t_coo *current2);
void			ft_menu(t_env *e);
int				ft_arrows(t_env *e, int keycode);
#endif
