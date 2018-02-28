/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 01:03:25 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/26 20:18:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISU_H
# define FT_VISU_H

# include "filler.h"
# include "mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH		1500
# define WIN_HEIGHT		800
# define BORDER_HEIGHT	75
# define COLOR_LEGEND_W	75
# define COLOR_LEGEND_H	75
# define COLOR_P1_FIRST	0xFF7373
# define COLOR_P1		0xff562c
# define COLOR_P2		0x2d7eff
# define COLOR_P2_FIRST	0x738FFF
# define COLOR_NEUTRAL	0x555555

typedef struct			s_image
{
	void				*ptr;
	int					*data;
	int					width;
	int					height;
	int					bpp;
	int					line_size;
	int					endian;
}						t_image;

typedef struct			s_fill_square
{
	int					start_x;
	int					start_y;
	int					end_x;
	int					end_y;
	double				x_scale;
	double				y_scale;
	int					color;
}						t_fill_square;

typedef struct			s_env
{
	t_game				game;
	void				*mlx;
	void				*win;
	t_image				image;
}						t_env;

int						ft_visu_parse(t_env *e, char *str);
void					ft_update_name(t_env *e, char *str);
void					ft_update_score(t_env *e, char *str);
int						ft_parse_game_visu(t_env *e);
int						ft_get_new_image(t_env *e, int width, int height);
void					ft_display_game(t_env *e);
void					ft_put_image(t_env *e, int width, int height);
int						ft_exit(int keycode, t_env *e);
#endif
