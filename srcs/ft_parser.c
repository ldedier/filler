/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:02:49 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/25 23:34:17 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_update_board(t_game *game, char *str)
{
	if (!game->init)
	{
		ft_get_map_dimensions(&(game->board), str);
		if (!(game->board.map =
			ft_create_split(game->board.height, game->board.width)))
			return (-1);
		if (!(game->map_tracker =
			ft_create_split_square(game->board.height, game->board.width)))
			return (-1);
		game->init = 1;
	}
	game->parser.to_parse = game->board.height + 2;
	game->parser.precised_to_parse = 1;
	game->parser.object_parsed = e_board_parse;
	return (0);
}

int		ft_update_piece(t_game *game, char *str)
{
	ft_get_piece_dimensions(&(game->piece), str);
	if (!(game->piece.desc =
				ft_create_split(game->piece.height, game->piece.width)))
		return (-1);
	game->parser.to_parse = game->piece.height;
	game->parser.object_parsed = e_piece_parse;
	return (0);
}

int		ft_parse_object(t_game *game, char *str)
{
	if (ft_strncmp(str, "   ", 3))
	{
		if (game->parser.object_parsed == e_board_parse &&
				game->board.height -
				game->parser.to_parse + 1 >= 0 && game->board.height -
				game->parser.to_parse + 1 < game->board.height &&
				(int)ft_strlen(str) >= 4 + game->board.width)
			ft_strcpy(game->board.map[game->board.height -
				game->parser.to_parse + 1], (&str[4]));
		else if ((int)ft_strlen(str) >= game->piece.width &&
				game->piece.height - game->parser.to_parse >= 0 &&
				game->piece.height - game->parser.to_parse < game->piece.height)
			ft_strcpy(game->piece.desc[game->piece.height -
				game->parser.to_parse], str);
		else
		{
			ft_putendl_fd("formatting error.", 2);
			return (-1);
		}
	}
	game->parser.to_parse--;
	return (0);
}

int		ft_parse(t_game *game, char *str)
{
	if (!game->init && !ft_strncmp(str, "$$$", 3))
	{
		game->side = ((str[10] == '1') ? 'O' : 'X');
		game->enemy_side = (game->side == 'O' ? 'X' : 'O');
	}
	else if (!ft_strncmp(str, "Plateau", 7))
	{
		if (ft_update_board(game, str) == -1)
			return (-1);
	}
	else if (!ft_strncmp(str, "Piece", 5))
	{
		if (ft_update_piece(game, str) == -1)
			return (-1);
	}
	else
	{
		if (ft_parse_object(game, str) == -1)
			return (-1);
	}
	return (0);
}
