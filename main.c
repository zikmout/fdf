/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:18:48 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/07 15:55:29 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	main(int ac, char **av)
{
	t_env	*e;
	t_coo	*begin;

	begin = NULL;
	e = NULL;
	if (!(begin = (t_coo *)ft_memalloc(sizeof(t_coo))))
		return (0);
	e = init_struct();
	begin->next = NULL;
	get_buffer(av, &begin);
	e->head = &begin;
	launch_win(e);
	return (0);
}
