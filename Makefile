NAME = fractol

HEADER = fractal.h

FLAGS = -Wall -Wextra -Werror -I $(HEADER)

MLX = -lmlx -framework AppKit -framework OpenGl -O3

LIB = ./libft/libft.a

SRC_FILES = 	main.c \
				fractal_mandelbrot.c \
				validation.c \
				start_fractal.c \
				evets_on_win.c \
				fractal_julia.c \
				fractal_serpinskogo.c \
				options_for_fractals.c \
				for_colors.c \
				evets_on_win_2.c \

BIN_FILES = $(SRC_FILES:.c=.o)

all: libft/libft.a $(NAME)

libft/libft.a:
	make -C ./libft/

libclean:
	make -C ./libft/ clean

libfclean:
	make -C ./libft/ fclean

$(NAME): $(BIN_FILES)
	gcc -o $(NAME) $(BIN_FILES) $(FLAGS) $(MLX) $(LIB)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BIN_FILES)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all