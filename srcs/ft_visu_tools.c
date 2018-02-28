/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 22:27:14 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/26 20:20:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <stdio.h>

int		ft_get_new_image(t_env *e, int width, int height)
{
	e->image.ptr = mlx_new_image(e->mlx, width, height);
	e->image.width = width;
	e->image.height = height;
	e->image.data = (int *)(mlx_get_data_addr(e->image.ptr, &(e->image.bpp),
				&(e->image.line_size), &(e->image.endian)));
	return (0);
}

int		ft_parse_game_visu(t_env *e)
{
	char	*str;
	int		ret;

	while ((e->game.parser.to_parse || !e->game.parser.precised_to_parse) &&
			(ret = get_next_line(0, &str)) > 0)
	{
		if (ft_visu_parse(e, str) == -1)
			return (1);
		ft_strdel(&str);
	}
	ft_strdel(&str);
	e->game.parser.precised_to_parse = 0;
	return (0);
}

void	ft_put_image(t_env *e, int x, int y)
{
	mlx_put_image_to_window(e->mlx, e->win, e->image.ptr, x, y);
}

int		ft_exit(int keycode, t_env *e)
{
	(void)e;
	(void)keycode;
	exit(0);
	return (0);
}
