/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 22:27:14 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/26 20:19:07 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		key_hook_interactive(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		ft_parse_game_visu(e);
		ft_display_game(e);
	}
	return (0);
}

int		key_hook_none(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		init_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "Filler_visu");
	ft_get_new_image(e, WIN_WIDTH, WIN_HEIGHT - BORDER_HEIGHT);
	e->game.init = 0;
	return (0);
}

int		loop_hook(t_env *e)
{
	ft_parse_game_visu(e);
	ft_display_game(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	init_env(&e);
	if (argc == 2 && !ft_strcmp(argv[1], "-i"))
	{
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, &key_hook_interactive, &e);
		ft_parse_game_visu(&e);
		ft_display_game(&e);
	}
	else
	{
		mlx_loop_hook(e.mlx, loop_hook, &e);
		mlx_hook(e.win, KEYPRESS, KEYPRESSMASK, &key_hook_none, &e);
	}
	mlx_hook(e.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, ft_exit, &e);
	mlx_loop(e.mlx);
	return (0);
}
