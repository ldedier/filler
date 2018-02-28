/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:04:29 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/21 00:22:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**ft_create_split(int height, int width)
{
	char	**res;
	int		i;

	if (!(res = malloc(sizeof(char *) * (height + 1))))
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!(res[i] = malloc(sizeof(char) * (width + 1))))
			return (NULL);
		i++;
	}
	res[i] = 0;
	return (res);
}

t_square	**ft_create_split_square(int height, int width)
{
	t_square	**res;
	int			i;

	if (!(res = malloc(sizeof(t_square *) * (height + 1))))
		return (NULL);
	i = 0;
	while (i < height)
	{
		if (!(res[i] = malloc(sizeof(t_square) * (width + 1))))
			return (NULL);
		i++;
	}
	res[i] = 0;
	return (res);
}

void		ft_display_pos(t_xy xy)
{
	ft_putnbr(xy.y);
	ft_putchar(' ');
	ft_putnbr(xy.x);
	ft_putchar('\n');
}

int			ft_is_enemy(char side, char undefined)
{
	if (side == 'O')
		return (undefined == 'X');
	else
		return (undefined == 'O');
}

char		get_enemy(char c)
{
	if (c == 'X')
		return ('O');
	return ('X');
}
