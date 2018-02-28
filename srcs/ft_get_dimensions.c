/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dimensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:10:20 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/20 19:50:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_map_dimensions(t_board *board, char *str)
{
	int height;
	int i;

	i = 1;
	height = ft_atoi(&(str[8]));
	board->height = height;
	while (height / 10 > 0)
	{
		height = height / 10;
		i++;
	}
	board->width = ft_atoi(&(str[8 + i]));
}

void	ft_get_piece_dimensions(t_piece *piece, char *str)
{
	int height;
	int i;

	i = 1;
	height = ft_atoi(&(str[6]));
	piece->height = height;
	while (height / 10 > 0)
	{
		height = height / 10;
		i++;
	}
	piece->width = ft_atoi(&(str[6 + i]));
}
