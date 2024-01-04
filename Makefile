NAME = Cub3d
BONUS = Cub3d_bonus

C_BLUE  = \033[1;34m
C_CYAN  = \033[1;36m
C_RESET = \033[34m

CC      = cc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror -I./includes -I ./MLX42/include/MLX42 -g 

MLX =  -framework OpenGl -framework AppKit -lglfw -L ~/.brew/opt/glfw/lib

M_HEADER  = mandatory/includes/cub3d.h
B_HEADER  = bonus/includes/cub3d.h

O_DIR   := Exec_Obj

LIB = MLX42/libmlx42.a

M_PARS = $(addprefix mandatory/parsing/, check_map.c check_map_wall.c count_Contents.c last_new_map.c \
	check_map_name.c set_dirr_floor.c read_map.c check_valid_map.c palyer_pos.c parsing.c check_open_file.c)

M_UTIL = $(addprefix mandatory/utils/, get_next_line_utils.c get_next_line.c ft_strlen.c ft_calloc.c size_map.c is_all_digitcomma.c\
	ft_strcmp.c ft_strlcpy.c ft_strdup.c ft_strjoin.c ft_split.c ft_substr.c line_is_space.c free_all.c ft_atoi.c \
	ft_strtrim.c set_size_map.c error_map.c ft_putstr_fd.c ft_putchar_fd.c ft_strstr.c)

M_EXEC = $(addprefix mandatory/executable/, set_map.c set_map_utils.c cast_rays.c mlx_func.c update_moves.c \
		update_rotation.c update_map.c draw_shapes.c cast_rays_utils.c)

B_PARS = $(addprefix bonus/parsing/, check_map.c check_map_wall.c count_Contents.c last_new_map.c \
	check_map_name.c set_dirr_floor.c read_map.c check_valid_map.c palyer_pos.c parsing.c check_open_file.c)

B_UTIL = $(addprefix bonus/utils/, get_next_line_utils.c get_next_line.c ft_strlen.c ft_calloc.c size_map.c is_all_digitcomma.c\
	ft_strcmp.c ft_strlcpy.c ft_strdup.c ft_strjoin.c ft_split.c ft_substr.c line_is_space.c free_all.c ft_atoi.c \
	ft_strtrim.c set_size_map.c error_map.c ft_putstr_fd.c ft_putchar_fd.c ft_strstr.c)

B_EXEC = $(addprefix bonus/executable/, set_map.c set_map_utils.c cast_rays.c mlx_func.c update_moves.c \
		update_rotation.c update_map.c draw_shapes.c cast_rays_utils.c)

M_SRCS = $(M_UTIL) $(M_PARS) $(M_EXEC) mandatory/cub3d.c
M_OBJS = $(patsubst %.c,$(O_DIR)/%.o,$(M_SRCS))

B_SRCS = $(B_UTIL) $(B_PARS) $(B_EXEC) bonus/cub3d.c
B_OBJS = $(patsubst %.c,$(O_DIR)/%.o,$(B_SRCS))


all: mlx $(NAME)

bonus: mlx $(BONUS)

mlx:
	make -C ./MLX42

$(NAME): $(M_OBJS) $(M_HEADER)
	@$(CC) $(CFLAGS) $(M_OBJS) $(LIB) -o $(NAME) $(MLX)
	@echo "$(C_BLUE)		✅ Compilation completed successfully!$(C_RESET)"

$(BONUS): $(B_OBJS) $(B_HEADER) 
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIB) -o $(BONUS) $(MLX)
	@echo "$(C_BLUE)		✅ Compilation of bonus completed successfully!$(C_RESET)"

$(O_DIR)/%.o: %.c $(B_HEADER) $(M_HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@$(RM) $(O_DIR)
	@echo "$(C_CYAN)🗑️  Object Directory has been removed......$(C_RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(C_CYAN)	🚀 'Cub3d' executable has been removed.....$(C_RESET)"

re: fclean all

.PHONY: all clean fclean re bonus