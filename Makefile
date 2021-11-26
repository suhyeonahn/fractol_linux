NAME = fractol

NAME_BONUS = fractol_bonus

SRC = main.c \
	mandelbrot.c \
	julia.c \
	init.c \
	utils.c \
	mouse.c	\
	key.c

SRC_BONUS = main_bonus.c \
		mandelbrot_bonus.c \
		julia_bonus.c \
		init_bonus.c \
		utils_bonus.c \
		mouse_bonus.c \
		key_bonus.c

LIBRARIES = -L. -lmlx -lm -lbsd -lX11 -lXext

LIBMLX = libmlx.a

INC_HEADER = includes

DIR_S = srcs

SRCS = $(addprefix ${DIR_S}/, ${SRC})

OBJS = $(SRCS:.c=.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

INC_HEADER_BONUS = includes_bonus

DIR_S_BONUS = srcs_bonus

SRCS_BONUS = $(addprefix ${DIR_S_BONUS}/, ${SRC_BONUS})

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) :	$(OBJS) $(LIBMLX)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBRARIES) -I$(INC_HEADER)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBMLX)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBRARIES) -I$(INC_HEADER_BONUS)

$(LIBMLX):
			$(MAKE) -C mlx_linux
			mv mlx_linux/$(LIBMLX) .

all	: $(NAME)

bonus	: $(NAME_BONUS)

clean	:
			rm -rf $(OBJS) $(OBJS_BONUS)
			$(MAKE) -C mlx_linux clean

fclean	: clean
			rm -rf $(NAME) $(NAME_BONUS) $(LIBMLX)

re : fclean all

.PHONY: re clean fclean all