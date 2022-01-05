CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
MLX_FLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_NAME	= libmlx.a
MLX_DIR		= ./mlx/
MLX			= $(addprefix $(MLX_DIR), $(MLX_NAME))

LIBFT_NAME	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC_LINK	= -I./includes/
NAME		= cub3d
SRC_DIR		= ./src/

C_FILES		= get_next_line.c					\
			  get_next_line_utils.c				\
			  key_hook.c						\
			  main.c							\
			  parser_check_invalid_type_data.c	\
			  parser_check_type_data.c			\
			  parser_check_param.c				\
			  parser_check_type_id.c			\
			  parser_get_type_data.c			\
			  parser_utils.c					\
			  parser.c							\
			  utils.c

SRCS		= $(addprefix $(SRC_DIR), $(C_FILES))
OBJS		= $(SRCS:.c=.o)

%.o			: %.c
	gcc -c $(CFLAGS) -Imlx $(INC_LINK) $< -o $@

all			: $(NAME)

bonus		: all

parser		: $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LFLAGS)

$(NAME)		: $(MLX) $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(MLX) -o $(NAME) $(LFLAGS)

$(LIBFT)	:
	@make all -C $(LIBFT_DIR)

$(MLX)		:
	@make all -C $(MLX_DIR)

clean		:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean		: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re			: fclean all

.PHONY		: all bonus clean fclean re
