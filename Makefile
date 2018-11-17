# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyeo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 14:15:58 by jyeo              #+#    #+#              #
#    Updated: 2018/01/25 00:00:51 by jyeo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VISU = visu-hex

LEM = lem_in

FLAG = -Wall -Wextra -Werror

CC = gcc

SRC =       		srcs/lem_in/parse.c\
					srcs/lem_in/process_room.c\
					srcs/lem_in/process_link.c\
					srcs/lem_in/utils.c\

LEM_SRC = 			srcs/lem_in/ant_utils.c\
					srcs/lem_in/check_valid.c\
					srcs/lem_in/get_path.c\
					srcs/lem_in/main.c\
					srcs/lem_in/solver.c\

VISU_SRC = 			srcs/visu/animation.c\
					srcs/visu/ant_pixel.c\
					srcs/visu/ant_visu.c\
					srcs/visu/draw_map.c\
					srcs/visu/draw.c\
					srcs/visu/hook.c\
					srcs/visu/visu.c\

INCLUDES = -I includes

OBJ = $(SRC:.c=.o)
LEM_OBJ = $(LEM_SRC:.c=.o)
VISU_OBJ = $(VISU_SRC:.c=.o)
LIBS = -L libft/ -lft
MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx
OPENGL = -framework OpenGL -framework Appkit
ALL_OBJ = $(OBJ) $(LEM_OBJ) $(VISU_OBJ)

all: lib $(VISU) lem_in

lib:
	@make -C libft/

lem_in: $(LEM_OBJ) $(OBJ)
	$(CC) $(FLAG) -o $(LEM) $(LEM_OBJ) $(OBJ) $(LIBS)

$(LEM_OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

$(VISU): $(VISU_OBJ) $(OBJ)
	$(CC) -o $(VISU) $(VISU_OBJ) $(OBJ) $(LIBS) $(MLX) $(OPENGL)

$(VISU_OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

$(OBJ): %.o: %.c
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(ALL_OBJ)
	make clean -C libft/

fclean:	clean
	@/bin/rm -f $(LEM)
	@/bin/rm -f $(VISU)
	make fclean -C libft/

re:	fclean all
