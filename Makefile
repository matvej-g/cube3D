NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -fsanitize=address -g
LDFLAGS		:= -fsanitize=address
LIBMLX		:= ./MLX42
LIBLIBFT	:= ./libft
HEADERS		:= -I $(LIBMLX)/include/MLX42 -I ./get_next_line
#LIBS		:= $(LIBLIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS		:= $(LIBLIBFT)/libft.a $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit


SRCS	:=	main.c \
			parse_map.c \
			parse_line.c \
			valid_map.c \
			create_player.c \
			draw_map.c

OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		mkdir -p libs && \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) && \
		cmake -S $(LIBMLX) -B $(LIBMLX)/build && \
		make -C $(LIBMLX)/build -j4; \
	fi

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBLIBFT)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBLIBFT) clean
	@rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBLIBFT) fclean
	@rm -rf libs
	@rm -rf $(NAME)

re: clean all

.PHONY: all libmlx clean fclean re