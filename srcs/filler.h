/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:51:51 by ldedier           #+#    #+#             */
/*   Updated: 2018/02/21 00:42:05 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libft/libft.h"

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef	struct		s_piece
{
	int				width;
	int				height;
	char			**desc;
}					t_piece;

typedef struct		s_board
{
	int				width;
	int				height;
	char			**map;
}					t_board;

typedef enum		e_object_parsed
{
	e_board_parse,
	e_piece_parse
}					t_object_parsed;

typedef struct		s_parser
{
	int				to_parse;
	int				precised_to_parse;
	t_object_parsed	object_parsed;
}					t_parser;

/*
** describe the distance to its closest filled block.
*/
typedef struct		s_square
{
	int				x;
	int				y;
	int				distance;
	char			seed;
	char			final_seed;
	char			final_distance;
}					t_square;

typedef struct		s_valider
{
	int				x;
	int				y;
	int				sharing_block;
}					t_valider;

typedef struct		s_game
{
	t_board			board;
	t_piece			piece;
	t_parser		parser;
	t_square		**map_tracker;
	t_list			*square_queue;
	int				over;
	char			side;
	char			enemy_side;
	int				init;
	int				score_p1;
	int				score_p2;
}					t_game;

int					ft_parse(t_game *game, char *str);
t_xy				ft_get_position(t_game *game);
void				ft_display_pos(t_xy pos);
char				**ft_create_split(int height, int width);
t_square			**ft_create_split_square(int height, int width);
void				ft_get_map_dimensions(t_board *board, char *str);
void				ft_get_piece_dimensions(t_piece *piece, char *str);
void				ft_debug_game(t_game game);
void				ft_debug_tracker(t_game game);
void				ft_debug_square(t_square square);
void				ft_debug(char *str);
int					ft_is_enemy(char side, char undefined);
int					ft_process_game_count(t_game *game);
void				ft_init_map_tracker(t_game *game);
void				ft_reset_map_tracker(t_game *game);
void				ft_process_game_dists(t_game *game);
void				ft_update_game_dists(t_game *game);
void				ft_add_piece_weight(t_game *game, int x, int y);
char				get_enemy(char c);
int					ft_is_valid_pos(int x, int y, t_game game);
#endif
