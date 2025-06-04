# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 19:03:59 by mcaro-ro          #+#    #+#              #
#    Updated: 2025/03/08 23:20:17 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = libft.a

# Compilation settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source Dirs
GNL = gnl

# Source fiiles
SOURCE = ft_isalpha.c 					\
		ft_isascii.c 					\
		ft_isdigit.c 					\
		ft_isalnum.c 					\
		ft_isprint.c 					\
		ft_strlen.c 					\
		ft_memset.c 					\
		ft_bzero.c 						\
		ft_memcpy.c 					\
		ft_memmove.c 					\
		ft_strlcpy.c 					\
		ft_strlcat.c 					\
		ft_toupper.c 					\
		ft_tolower.c 					\
		ft_strchr.c 					\
		ft_strrchr.c 					\
		ft_strncmp.c 					\
		ft_memchr.c 					\
		ft_memcmp.c 					\
		ft_strnstr.c 					\
		ft_atoi.c 						\
		ft_calloc.c 					\
		ft_strdup.c 					\
		ft_substr.c 					\
		ft_strjoin.c 					\
		ft_strtrim.c 					\
		ft_split.c 						\
		ft_itoa.c 						\
		ft_strmapi.c 					\
		ft_striteri.c 					\
		ft_putchar_fd.c 				\
		ft_putstr_fd.c 					\
		ft_putendl_fd.c 				\
		ft_putnbr_fd.c 					\
		$(GNL)/get_next_line.c			\
		$(GNL)/get_next_line_utils.c	\

		
BONUS = ft_lstnew_bonus.c 				\
		ft_lstadd_front_bonus.c 		\
		ft_lstadd_back_bonus.c 			\
		ft_lstsize_bonus.c 				\
		ft_lstlast_bonus.c 				\
		ft_lstdelone_bonus.c 			\
		ft_lstclear_bonus.c 			\
		ft_lstiter_bonus.c				\
		ft_lstmap_bonus.c 				\


# Objects files
OBJECTS = $(SOURCE:.c=.o)
BOBJECTS = $(BONUS:.c=.o)

# Link object files
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(BOBJECTS):
	${CC} ${CFLAGS} -c $(BONUS)
	ar -rcs ${NAME} ${BOBJECTS}

# Default target to build the project
all: $(NAME)

bonus: $(NAME) $(BOBJECTS)

# Clean up object files
clean:
	@rm -f $(OBJECTS) $(BOBJECTS)

# Clean up all generated files
fclean: clean
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

.DEFAULT_GOAL := all
.PHONY: all bonus clean fclean re
