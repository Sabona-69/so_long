NAME			= so_long

BNAME			= so_long_bonus

CC				= cc

RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror #-g -fsanitize=address

SRC				= mandatory/parse/map.c mandatory/parse/map2.c \
				  mandatory/utils/utils.c mandatory/utils/utils2.c mandatory/utils/utils3.c mandatory/utils/get_next_line.c \
				  mandatory/handle_errors.c mandatory/so_long.c \
				  mandatory/game/game.c mandatory/game/game_utils.c

BSRC			= bonus/parse/map_b.c bonus/parse/map2_b.c \
				  bonus/utils/utils_b.c bonus/utils/utils2_b.c bonus/utils/utils3_b.c bonus/utils/get_next_line_b.c \
				  bonus/handle_errors_b.c bonus/so_long_b.c \
				  bonus/game/game_b.c bonus/game/game_utils_b.c bonus/game/game_utils_b2.c bonus/game/enemy_patrol.c  bonus/game/game_output.c  bonus/game/animation.c

OBJ				= $(SRC:.c=.o)

BOBJ			= $(BSRC:.c=.o)

all				: $(NAME)

bonus			: $(BNAME)

$(NAME)			: $(OBJ)
					@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
					@echo Mandatory make Success

$(BNAME)		: $(BOBJ)
					$(CC) $(CFLAGS) $(BOBJ) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)
					@echo Bonus make Success

mandatory/%.o	: mandatory/%.c include/so_long.h
					$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o		: bonus/%.c include/bonus.h
					$(CC) $(CFLAGS) -c $< -o $@

clean			:
					@$(RM) $(OBJ) $(BOBJ)

fclean			: clean
					@$(RM) $(NAME) $(BNAME)

re				: fclean all

A				: bonus clean
