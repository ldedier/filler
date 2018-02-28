/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 22:27:14 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/25 23:48:27 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		get_color(char c)
{
	if (c == 'o')
		return (COLOR_P1_FIRST);
	else if (c == 'O')
		return (COLOR_P1);
	else if (c == 'x')
		return (COLOR_P2_FIRST);
	else if (c == 'X')
		return (COLOR_P2);
	else
		return (COLOR_NEUTRAL);
}

void	ft_fill_square(t_env *e, int x, int y)
{
	t_fill_square	fill;
	int				i;
	int				j;

	fill.x_scale = e->image.width / (double)e->game.board.width;
	fill.y_scale = e->image.height / (double)e->game.board.height;
	fill.start_x = x * fill.x_scale;
	fill.end_x = fill.start_x + fill.x_scale;
	fill.start_y = y * fill.y_scale;
	fill.end_y = fill.start_y + fill.y_scale;
	fill.color = get_color(e->game.board.map[y][x]);
	i = fill.start_y;
	while (i < fill.end_y)
	{
		j = fill.start_x;
		while (j < fill.end_x)
		{
			e->image.data[i * e->image.width + j] = fill.color;
			j++;
		}
		i++;
	}
}

void	ft_add_grid_vertical(t_env *e, int x, int y, t_fill_square *fill)
{
	int i;
	int j;

	fill->start_x = x * fill->x_scale - 1;
	fill->end_x = x * fill->x_scale + 1;
	fill->start_y = y * fill->y_scale;
	fill->end_y = fill->y_scale * (y + 1);
	i = fill->start_y;
	while (i < fill->end_y)
	{
		j = fill->start_x;
		if (i >= 0 && i < e->image.height)
		{
			while (j < fill->end_x)
			{
				if (j >= 0 && j < e->image.width)
					e->image.data[i * e->image.width + j] = 0x000000;
				j++;
			}
		}
		i++;
	}
}

void	ft_add_grid_horizontal(t_env *e, int x, int y, t_fill_square *fill)
{
	int i;
	int j;

	fill->start_x = x * fill->x_scale;
	fill->end_x = fill->x_scale * (x + 1);
	fill->start_y = y * fill->y_scale - 1;
	fill->end_y = y * fill->y_scale + 1;
	i = fill->start_y;
	while (i < fill->end_y)
	{
		j = fill->start_x;
		if (i >= 0 && i < e->image.height)
		{
			while (j < fill->end_x)
			{
				if (j >= 0 && j < e->image.width)
					e->image.data[i * e->image.width + j] = 0x000000;
				j++;
			}
		}
		i++;
	}
}

void	ft_display_game(t_env *e)
{
	t_fill_square	fill;
	int				i;
	int				j;

	if (e->game.init)
	{
		fill.x_scale = e->image.width / (double)e->game.board.width;
		fill.y_scale = e->image.height / (double)e->game.board.height;
		i = 0;
		while (i < e->game.board.height)
		{
			j = 0;
			while (j < e->game.board.width)
			{
				ft_fill_square(e, j, i);
				ft_add_grid_vertical(e, j, i, &fill);
				ft_add_grid_horizontal(e, j, i, &fill);
				j++;
			}
			i++;
		}
		ft_put_image(e, 0, BORDER_HEIGHT);
	}
	else
		exit(1);
}
