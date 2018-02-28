/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:09:27 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/21 00:08:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_process_game_count(t_game *game)
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = 0;
	while (i < game->board.height)
	{
		j = 0;
		while (j < game->board.width)
		{
			if (game->map_tracker[i][j].final_seed == game->side)
				ret++;
			else if (game->map_tracker[i][j].final_seed == game->enemy_side)
				ret--;
			j++;
		}
		i++;
	}
	return (ret);
}

void	ft_reset_map_tracker(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->board.height)
	{
		j = 0;
		while (j < game->board.width)
		{
			game->map_tracker[i][j].final_seed = game->map_tracker[i][j].seed;
			game->map_tracker[i][j].final_distance =
				game->map_tracker[i][j].distance;
			j++;
		}
		i++;
	}
}

void	ft_init_map_tracker(t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < game->board.height)
	{
		j = 0;
		while (j < game->board.width)
		{
			game->map_tracker[i][j].x = j;
			game->map_tracker[i][j].y = i;
			if ((c = game->board.map[i][j]) != '.')
			{
				game->map_tracker[i][j].distance = 0;
				ft_lstadd(&(game->square_queue),
					ft_lstnew_ptr(&(game->map_tracker[i][j]),
						sizeof(t_square)));
			}
			game->map_tracker[i][j].seed = c;
			j++;
		}
		i++;
	}
}

/*
** modify the map tracker to take the piece weight in account
*/

void	ft_add_piece_weight(t_game *game, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < game->piece.height)
	{
		j = 0;
		while (j < game->piece.width)
		{
			if (y + i >= 0 && y + i < game->board.height
					&& x + j >= 0 && x + j < game->board.width
						&& game->board.map[y + i][x + j] == 'P')
			{
				game->map_tracker[y + i][x + j].final_distance = 0;
				game->map_tracker[y + i][x + j].final_seed = game->side;
				ft_lstadd(&(game->square_queue),
				ft_lstnew_ptr(&(game->map_tracker[y + i][x + j]),
					sizeof(t_square)));
			}
			j++;
		}
		i++;
	}
	ft_update_game_dists(game);
}
