NAME = so_long

NAME_BONUS = so_long_bonus

LIBFT = ./libft/libft.a
LIBGNL = ./get_next_line/libgnl.a

SRCS =	./mandatory/src/so_long.c \
		./mandatory/src/utils.c \
		./mandatory/src/check_map.c \
		./mandatory/src/parsing_file_to_map.c \
		./mandatory/src/check_no_exit.c \
		./mandatory/src/init_window_with_map.c \
		./mandatory/src/my_hook_param.c \
		./mandatory/src/move_player.c

SRCS_BONUS =	./bonus/src/so_long_bonus.c \
				./bonus/src/utils_bonus.c \
				./bonus/src/check_map_bonus.c \
				./bonus/src/parsing_file_to_map_bonus.c \
				./bonus/src/check_no_exit_bonus.c \
				./bonus/src/init_window_with_map_bonus.c \
				./bonus/src/my_hook_param_bonus.c \
				./bonus/src/move_player_bonus.c \
				./bonus/src/animation_exit_and_player_bonus.c

HEADER = ./mandatory/include/so_long.h
HEADER_BONUS = ./bonus/include/so_long_bonus.h

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CFLAGS = -Werror -Wextra -Wall
FLAGS_FOR_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(LIBFT) $(LIBGNL)

CC = cc

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT) $(LIBGNL)
	$(CC) -I $(HEADER) $(OBJS) $(LIBFT) $(LIBGNL) $(FLAGS_FOR_MLX) -o $(NAME)

bonus: $(NAME_BONUS) $(LIBFT) $(LIBGNL)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT) $(LIBGNL)
	$(CC) -I $(HEADER_BONUS) $(OBJS_BONUS) $(LIBFT) $(LIBGNL) $(FLAGS_FOR_MLX) -o $(NAME_BONUS)

$(LIBFT) : 
	@make -C ./libft


$(LIBGNL) : 
	@make -C ./get_next_line

clean:
	@make clean -C ./libft
	@make clean -C ./get_next_line
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -rf $(OBJS) $(NAME) $(OBJS_BONUS) $(NAME_BONUS)

re: fclean all

.PHONY:	all clean fclean re