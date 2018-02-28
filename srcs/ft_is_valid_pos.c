/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:09:27 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/21 00:56:54 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_has_issue(t_valider *valider, int j, int i, t_game game)
{
	if (valider->y + i < game.board.height && valider->y + i >= 0 &&
			valider->x + j < game.board.width && valider->x + j >= 0)
	{
		if (game.piece.desc[i][j] == '*' &&
				ft_is_enemy(game.side,
					game.board.map[valider->y + i][valider->x + j]))
			return (1);
		else if ((game.piece.desc[i][j] == '*' &&
			game.board.map[valider->y + i][valider->x + j] == game.side))
		{
			if (++(valider->sharing_block) > 1)
				return (1);
		}
	}
	else
	{
		if (game.piece.desc[i][j] == '*')
			return (1);
	}
	return (0);
}

/*
** verify if the piece can be set
*/

int		ft_is_valid_pos(int x, int y, t_game game)
{
	t_valider	valider;
	int			i;
	int			j;

	valider.x = x;
	valider.y = y;
	valider.sharing_block = 0;
	i = 0;
	while (i < game.piece.height)
	{
		j = 0;
		while (j < game.piece.width)
		{
			if (ft_has_issue(&valider, j, i, game))
				return (0);
			j++;
		}
		i++;
	}
	return (valider.sharing_block == 1);
}
