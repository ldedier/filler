# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 18:20:16 by ldedier           #+#    #+#              #
#    Updated: 2018/02/28 22:11:52 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ldedier.filler
VISU_NAME	= filler_visu

CC      = gcc

PWD = \"$(shell pwd)\"

CFLAGS   = -DPATH=$(PWD) -Wall -Wextra -Werror

SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
LIBFTDIR = libft

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX  = ft_parser.c ft_tools.c ft_get_position.c\
				  ft_get_dimensions.c main.c ft_breadth_first_search.c\
				  ft_map_tracker.c ft_is_valid_pos.c\

VSRCS_NO_PREFIX = ft_visu_parser.c ft_get_dimensions.c ft_tools.c main_visu.c\
				  ft_visu_update_info.c ft_visu_tools.c ft_visu_display.c

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))
VSOURCES = $(addprefix $(SRCDIR)/, $(VSRCS_NO_PREFIX))

INCLUDES = $(SRCDIR)/filler.h $(SRCDIR)/visu.h

OBJECTS = $(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))
VOBJECTS = $(addprefix $(OBJDIR)/, $(VSRCS_NO_PREFIX:%.c=%.o))

all: $(BINDIR)/$(NAME) $(BINDIR)/$(VISU_NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(CC) -c $< -o $@ $(CFLAGS) 

$(BINDIR)/$(NAME): $(OBJECTS)
	@make -C $(LIBFTDIR)
	@$(CC) -o $@ $^ $(CFLAGS) -L $(LIBFTDIR) -lft
	@cp $@ players
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(BINDIR)/$(VISU_NAME): $(VOBJECTS)
	@make -C $(LIBFTDIR)
	@$(CC) -o $@ $^ $(CFLAGS) -L $(LIBFTDIR) -lft -lmlx -framework OpenGL -framework Appkit
	@echo "$(OK_COLOR)$(VISU_NAME) linked with success !$(EOC)"

clean:
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJECTS)
	@rm -f $(VOBJECTS)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(BINDIR)/$(NAME)
	@rm -f $(BINDIR)/$(VISU_NAME)

re: fclean all

.PHONY: all clean fclean re
