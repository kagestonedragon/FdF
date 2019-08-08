NAME = fdf

C = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = sources/color.c \
	   sources/draw_info.c \
	   sources/drawing.c \
	   sources/initialization.c \
	   sources/int.c \
	   sources/keyboard_control.c \
	   sources/main.c \
	   sources/mouse_control.c \
	   sources/points.c \
	   sources/projection.c \
	   sources/reader.c \
	   sources/vectors.c \
	   sources/ms.c

OBJS = color.o \
	   draw_info.o \
	   drawing.o \
	   initialization.o \
	   int.o \
	   keyboard_control.o \
	   main.o \
	   mouse_control.o \
	   points.o \
	   projection.o \
	   reader.o \
	   vectors.o \
	   ms.o

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft -L minilibx -lmlx -framework OpenGL -framework AppKIt

$(OBJS):
	$(CC) $(CFLAGS) -c $(SRCS) -I includes -I libft

lib:
	make -C libft
	make -C minilibx

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean
	make -C minilibx clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
