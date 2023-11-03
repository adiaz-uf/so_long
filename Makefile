NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

LIBFT_DIR = libft/
GNL_DIR = get_next_line/

SRC = src/so_long.c src/handle_input.c src/init_map.c src/ft_error.c \
		src/map_component.c src/check_map.c src/map_component2.c src/draw_map.c \
		src/map_size.c src/plyr_moves.c src/print_steps.c src/ft_free.c \
		src/check_ways.c src/check_file.c

OBJS = $(SRC:.c=.o)
	
INCLUDE = -L ./libft -lft

GREEN=\033[1;42m
RED=\033[1;31m
CYAN=\033[1;36m
END=\x1b[0m

S = sleep 0.7

$(NAME): $(OBJS)
		
		@make -C $(LIBFT_DIR)
		@echo "$(CYAN)Compiling libft...$(END)"
		@$(S)
		@echo "$(CYAN)¡Libft successfully compiled!$(END)"
		@$(S)
		@echo "$(CYAN)Compiling so_long...$(END)"
		@$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME) $(INCLUDE)
		@$(S)
		@echo "$(CYAN)Loading textures...$(END)"
		@$(S)
		@clear
		@echo "$(GREEN)¡Compilation Success, you can run So_long!$(END)\n"
	
all: $(NAME)

clean:
		@$(RM) $(OBJS) $(NAME)
		@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
		@$(RM) $(NAME)
		@cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus