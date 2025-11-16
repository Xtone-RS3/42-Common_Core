# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasoares <gasoares@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 16:39:18 by gasoares          #+#    #+#              #
#    Updated: 2025/10/31 12:02:45 by gasoares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libft folder and source files

LIBFT_SRCS = ft_atoi.c ft_is_x.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
		ft_bzero.c ft_itoa.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
		ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
		ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
		ft_memcpy.c ft_split.c ft_strlen.c ft_to_up_low.c \
		ft_memmove.c ft_strchr.c ft_strmapi.c \
		ft_memset.c ft_strdup.c ft_strncmp.c \
		ft_printf.c ft_putaddress.c ft_putchar.c ft_putnbr.c ft_putnbr_base.c ft_putstr_print.c

# Object files for ft_printf and libft
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Default target
all: $(NAME)

# Create the ft_printf library
$(NAME): $(LIBFT_OBJS)
	ar rcs $(NAME) $(LIBFT_OBJS)

# Rule to compile C files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(LIBFT_OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Mark targets as not files
.PHONY: all clean fclean re
