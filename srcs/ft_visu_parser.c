/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:12:22 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/25 23:39:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		ft_update_board(t_game *game, char *str)
{
	if (!game->init)
	{
		ft_get_map_dimensions(&(game->board), str);
		if (!(game->board.map = ft_create_split(game->board.height,
						game->board.width)))
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
	game->parser.to_parse = game->piece.height;
	game->parser.object_parsed = e_piece_parse;
	return (0);
}

void	ft_parse_object_visu(t_env *e, char *str)
{
	if (!ft_strncmp(str, "error:", 6))
		exit(1);
	if (!ft_strncmp(str, "<got", 4) || !ft_strncmp(str, "Player", 5))
		return ;
	else if (ft_strncmp(str, "   ", 3) &&
		ft_strncmp(str, "#", 1) && ft_strncmp(str, "launched", 8))
	{
		if (e->game.parser.object_parsed == e_board_parse &&
				e->game.board.height -
				e->game.parser.to_parse + 1 >= 0 && e->game.board.height -
				e->game.parser.to_parse + 1 < e->game.board.height &&
				(int)ft_strlen(str) >= 4 + e->game.board.width)
			ft_strcpy(e->game.board.map[e->game.board.height -
					e->game.parser.to_parse + 1], (&str[4]));
		else if (e->game.parser.object_parsed != e_piece_parse)
			exit(1);
	}
	e->game.parser.to_parse--;
}

int		ft_visu_parse(t_env *e, char *str)
{
	if (!ft_strncmp(str, "$$$", 3))
	{
		ft_update_name(e, str);
		return (0);
	}
	if (!ft_strncmp(str, "==", 2))
	{
		ft_update_score(e, str);
		return (0);
	}
	if (!ft_strncmp(str, "Plateau", 7))
	{
		if (ft_update_board(&(e->game), str) == -1)
			return (-1);
	}
	else if (!ft_strncmp(str, "Piece", 5))
	{
		if (ft_update_piece(&(e->game), str) == -1)
			return (-1);
	}
	else
		ft_parse_object_visu(e, str);
	return (0);
}
