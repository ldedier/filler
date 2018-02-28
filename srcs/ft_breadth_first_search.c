/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:09:27 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/20 23:55:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_izokay(int x, int y, t_game *game)
{
	return (x >= 0 && x < game->board.width
			&& y >= 0 && y < game->board.height);
}

void	ft_process_next(t_square *current, int add_x, int add_y, t_game *game)
{
	char c;

	if (ft_izokay(current->x + add_x, current->y + add_y, game))
	{
		if ((c = game->map_tracker[current->y + add_y]
			[current->x + add_x].seed) == '.')
		{
			game->map_tracker[current->y + add_y][current->x + add_x].seed =
				current->seed;
			game->map_tracker[current->y + add_y][current->x + add_x].distance =
				current->distance + 1;
			ft_lstpushback(&(game->square_queue),
			ft_lstnew_ptr(&(game->map_tracker[current->y + add_y]
				[current->x + add_x]), sizeof(t_square)));
		}
		else if (c == get_enemy(current->seed) &&
			game->map_tracker[current->y + add_y]
				[current->x + add_x].distance == current->distance + 1)
			game->map_tracker[current->y + add_y]
				[current->x + add_x].seed = 'E';
	}
}

void	ft_update_next(t_square *current, int add_x, int add_y, t_game *game)
{
	char c;

	if (ft_izokay(current->x + add_x, current->y + add_y, game))
	{
		if ((c = game->map_tracker[current->y + add_y]
			[current->x + add_x].final_distance)
				> current->final_distance + 1)
		{
			game->map_tracker[current->y + add_y]
				[current->x + add_x].final_seed = current->final_seed;
			game->map_tracker[current->y + add_y]
				[current->x + add_x].final_distance =
				current->final_distance + 1;
			ft_lstpushback(&(game->square_queue),
			ft_lstnew_ptr(&(game->map_tracker[current->y + add_y]
				[current->x + add_x]), sizeof(t_square)));
		}
		else if (c == get_enemy(current->final_seed) &&
			game->map_tracker[current->y + add_y]
				[current->x + add_x].final_distance ==
					current->final_distance + 1)
			game->map_tracker[current->y + add_y]
				[current->x + add_x].final_seed = 'E';
	}
}

void	ft_process_game_dists(t_game *game)
{
	t_square *current;

	while (game->square_queue != NULL)
	{
		current = (t_square *)(ft_lstpop(&(game->square_queue)));
		ft_process_next(current, -1, 0, game);
		ft_process_next(current, 1, 0, game);
		ft_process_next(current, 0, -1, game);
		ft_process_next(current, 0, 1, game);
	}
}

void	ft_update_game_dists(t_game *game)
{
	t_square *current;

	while (game->square_queue != NULL)
	{
		current = (t_square *)(ft_lstpop(&(game->square_queue)));
		ft_update_next(current, -1, 0, game);
		ft_update_next(current, 1, 0, game);
		ft_update_next(current, 0, -1, game);
		ft_update_next(current, 0, 1, game);
	}
}
