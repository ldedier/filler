/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:09:27 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/21 00:30:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy	ft_execute_move(t_game *game, int x, int y)
{
	t_xy	res;
	int		i;
	int		j;

	i = 0;
	while (i < game->piece.height)
	{
		j = 0;
		while (j < game->piece.width)
		{
			if (game->piece.desc[i][j] == '*')
			{
				if (game->board.map[y + i][x + j] == game->side)
				{
					res.x = x + j;
					res.y = y + i;
				}
				else
					game->board.map[y + i][x + j] = 'P';
			}
			j++;
		}
		i++;
	}
	return (res);
}

/*
** cancel a move given the position of the superposing piece
*/

void	ft_go_back_move(t_xy pos, t_game *game, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < game->piece.height)
	{
		j = 0;
		while (j < game->piece.width)
		{
			if (game->piece.desc[i][j] == '*')
			{
				if (y + i != pos.y || x + j != pos.x)
					game->board.map[y + i][x + j] = '.';
			}
			j++;
		}
		i++;
	}
}

/*
** returns the quality of a move (placing the given piece in (X,Y))
*/

int		ft_move_quality(int x, int y, t_game *game)
{
	t_xy	pos;
	int		ret;

	pos = ft_execute_move(game, x, y);
	ft_reset_map_tracker(game);
	ft_add_piece_weight(game, x, y);
	ret = ft_process_game_count(game);
	ft_go_back_move(pos, game, x, y);
	return (ret);
}

void	ft_init_get_pos(t_game *game, int *max_val)
{
	*max_val = -game->board.width * game->board.height;
	ft_init_map_tracker(game);
	ft_process_game_dists(game);
}

/*
** returns the best possible position for the given game / piece
*/

t_xy	ft_get_position(t_game *game)
{
	t_xy	res;
	int		i;
	int		j;
	int		max_val;
	int		val;

	ft_init_get_pos(game, &max_val);
	i = -game->piece.height;
	while (i < game->board.height)
	{
		j = -game->piece.width;
		while (j < game->board.width)
		{
			if ((ft_is_valid_pos(j, i, *game) &&
				(val = ft_move_quality(j, i, game)) > max_val))
			{
				res.x = j;
				res.y = i;
				max_val = val;
			}
			j++;
		}
		i++;
	}
	return (res);
}
