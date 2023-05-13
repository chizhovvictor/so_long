NAME = so_long

LIBFT = ./libft/libft.a
LIBGNL = ./get_next_line/libgnl.a

SRCS =	so_long.c \
		utils.c check_map.c \
		parsing_file_to_map.c \
		check_no_exit.c
#		init_window_with_map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall
FLAGS_FOR_MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(LIBFT) $(LIBGNL)

CC = cc

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT) $(LIBGNL)
	$(CC) $(OBJS) $(LIBFT) $(LIBGNL) $(FLAGS_FOR_MLX) -o $(NAME)

$(LIBFT) : $(OBJS)
	@make -C ./libft


$(LIBGNL) : $(OBJS)
	@make -C ./get_next_line

clean:
	@make clean -C ./libft
	@make clean -C ./get_next_line
	rm -rf $(OBJS)

fclean:
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -rf $(OBJS) $(NAME)

re: fclean all