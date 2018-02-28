/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:55:17 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/25 22:17:06 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_game(t_game *game)
{
	game->over = 0;
	game->init = 0;
	game->parser.precised_to_parse = 0;
	game->square_queue = NULL;
}

int		main(void)
{
	char	*str;
	int		ret;
	t_game	game;
	t_xy	pos;

	init_game(&game);
	while (!game.over)
	{
		while ((game.parser.to_parse || !game.parser.precised_to_parse) &&
			(ret = get_next_line(0, &str)) > 0)
		{
			if (ft_parse(&game, str) == -1)
				return (1);
			ft_strdel(&str);
		}
		ft_strdel(&str);
		if (!game.parser.precised_to_parse)
			return (1);
		pos = ft_get_position(&game);
		ft_display_pos(pos);
		game.parser.precised_to_parse = 0;
		ft_free_split(game.piece.desc);
	}
	return (0);
}
