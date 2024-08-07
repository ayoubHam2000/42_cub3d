# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 09:30:37 by aben-ham          #+#    #+#              #
#    Updated: 2022/06/03 18:28:16 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTIL_FILES = \
	utils/ft_arrlen.c \
	utils/ft_substr.c \
	utils/ft_atoi.c \
	utils/ft_memcpy.c \
	utils/ft_memset.c \
	utils/ft_split.c \
	utils/int_check.c \
	utils/msk_split.c \
	utils/ft_strchr.c \
	utils/ft_strdup.c \
	utils/ft_strjoin.c \
	utils/ft_strlcpy.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \
	utils/ft_strrchr.c \
	utils/ft_error.c \
	utils/ft_strtrim.c \
	utils/ft_itoa.c \
	utils/ft_str_replace.c \
	utils/ft_error_exit.c \
	utils/ft_strcmp.c \
	utils/ft_in.c \
	utils/min.c \
	utils/max.c \
	utils/ft_malloc/add_address.c \
	utils/ft_malloc/free_all.c \
	utils/ft_malloc/ft_addrs_exclude.c \
	utils/ft_malloc/malloc.c \
	utils/ft_malloc/malloc_error.c \
	utils/queue_c/q_clear.c \
	utils/queue_c/q_dequeue.c \
	utils/queue_c/q_enqueue.c \
	utils/get_next_line/get_next_line_utils.c \
	utils/get_next_line/get_next_line.c \
	utils/queue_c/q_init.c 

MainFiles = \
	_cub3d/events/exit_cube3d.c \
	_cub3d/events/on_key_up.c \
	_cub3d/events/on_key_down.c \
	_cub3d/events/perform_events.c \
	_cub3d/utils/color.c \
	_cub3d/utils/put_image.c \
	_cub3d/init/check_args.c \
	_cub3d/init/get_prog.c \
	_cub3d/init/init_sdl.c \
	_cub3d/ray_casting/ray_casting.c \
	_cub3d/setup/init_player.c \
	_cub3d/setup/load_map.c \
	_cub3d/setup/load_texture.c \
	_cub3d/setup/check_map.c \
	_cub3d/setup/load_types.c \
	_cub3d/setup/read_file.c \
	_cub3d/setup/setup.c \
	_cub3d/render/pixel.c \
	_cub3d/render/new_frame_image.c \
	_cub3d/start/game.c \
	_cub3d/start/start_game.c \

FILES = \
	$(UTIL_FILES) \
	$(MainFiles) \
	main.c

#-Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ./includes/
LINKING = -L/usr/local/lib -lSDL2 -lSDL2_image -lm
# -fsanitize=address

DEPFLAGS = -MMD -MF $(@:.o=.d)

NAME = cub3d.out

OBJ_DIR = _OUT/

OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

deps = $(OBJ:.o=.d)

all : $(NAME)


#$(COMPILE) -c $< -o $@

$(NAME) : $(OBJ)
	gcc $(OBJ) $(LINKING) -o $(NAME)

$(OBJ) : $(OBJ_DIR)%.o : %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) $(INCLUDE) -c $(@:_OUT/%.o=%.c) $(DEPFLAGS) -o $@

-include $(deps)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
