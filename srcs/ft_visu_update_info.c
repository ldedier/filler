/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu_update_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:06:20 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/20 23:09:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_update_name(t_env *e, char *str)
{
	int len;

	if ((len = ft_strlen(str)) > 23)
	{
		str[len - 1] = '\0';
		if (str[10] == '1')
			mlx_string_put(e->mlx, e->win, 75, 26, COLOR_P1, &(str[23]));
		else
		{
			mlx_string_put(e->mlx, e->win, e->image.width -
				ft_strlen(&(str[23])) * 10 - 75, 26, COLOR_P2, &(str[23]));
		}
	}
}

void	print_xpm(t_env *e, char *xpm, int x, int y)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(e->mlx, xpm, &(width), &(height));
	if (img == NULL)
	{
		ft_putendl_fd("mlx malloc error.", 2);
		exit(1);
	}
	mlx_put_image_to_window(e->mlx, e->win, img, x, y);
	mlx_destroy_image(e->mlx, img);
}

void	ft_add_crown(t_env *e)
{
	int diff;

	mlx_string_put(e->mlx, e->win, (WIN_WIDTH / 2) - 41,
		10, 0xffffff, "Final score");
	diff = e->game.score_p1 - e->game.score_p2;
	if (diff > 0)
		print_xpm(e, PATH"/resources/crown.xpm", (WIN_WIDTH / 2) - 150, -6);
	else if (diff < 0)
		print_xpm(e, PATH"/resources/crown.xpm", (WIN_WIDTH / 2) + 100, -6);
}

void	ft_update_score(t_env *e, char *str)
{
	int len;

	if ((len = ft_strlen(str)) > 10)
	{
		if (str[3] == 'O')
		{
			mlx_string_put(e->mlx, e->win, (WIN_WIDTH / 2) -
					(len - 10) * 10, 36, 0xffffff, &(str[10]));
			e->game.score_p1 = ft_atoi(&(str[10]));
		}
		else
		{
			str[8] = ':';
			mlx_string_put(e->mlx, e->win, (WIN_WIDTH / 2) + 10,
					36, 0xffffff, &(str[8]));
			e->game.score_p2 = ft_atoi(&(str[10]));
			ft_add_crown(e);
		}
	}
}
