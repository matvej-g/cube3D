# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 10:36:05 by wdegraf           #+#    #+#              #
#    Updated: 2025/02/23 15:22:03 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_isascii.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strrchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
		ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		ft_printf_xXpudi.c ft_printf.c ft_intlen.c ft_unsetenv.c \
		get_next_line.c get_next_line_utils.c ft_lstiter_f_bonus.c \
		ft_lstget.c ft_write.c ft_strcwords.c ft_ato_ssize_t.c \
		ft_fill.c ft_strcmp.c ft_isspace.c ft_realloc.c ft_setenv.c \
		ft_strcpy.c ft_strndup.c ft_strnlen.c ft_strncpy.c ft_strcwords_isspace.c \
		ft_strtok.c ft_strtok_thread.c ft_strstr.c ft_strcat.c \
		ft_strjoin_multiple.c ft_build_f_path.c ft_isupper.c \
		ft_isnumeric.c ft_write_smite.c  ft_magnitude.c \
		ft_str_end_with.c ft_check_wall.c ft_strspn.c ft_access.c \
		ft_strdup_double.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re