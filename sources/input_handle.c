/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:09:49 by ssicard           #+#    #+#             */
/*   Updated: 2016/03/04 08:34:46 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		rad_to_deg(int deg)
{
	return ((deg / 180.0f) * M_PI);
}

t_coo		*get_buffer(char **av, t_coo **head)
{
	int		ret;
	int		fd;
	char	*line;
	int		y;
	t_coo	*cur;

	cur = NULL;
	*head = NULL;
	y = 0;
	ret = 0;
	fd = open(av[1], O_RDONLY);
	if (get_next_line(fd, &line) == -1)
		exit(0);
	else
	{
		while ((ret = get_next_line(fd, &line) > 0))
		{
			head = get_map(line, head, y);
			y++;
		}
	}
	close(fd);
	cur = *head;
	return (cur);
}

t_coo		**get_map(char *str, t_coo **head, int y)
{
	int		i;
	char	*tmp;
	int		x;
	int		z;

	x = 0;
	i = 0;
	z = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			tmp = ft_strdup("\0");
			while (ft_isdigit(str[i]) == 1)
			{
				tmp = ft_strjoina(tmp, str[i]);
				i++;
			}
			z = ft_atoi(tmp);
			ft_list_push_back(head, x, y, z);
			x++;
		}
		i++;
	}
	return (head);
}
