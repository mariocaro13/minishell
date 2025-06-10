# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/10 20:22:12 by mcaro-ro          #+#    #+#              #
#    Updated: 2025/06/10 22:37:37 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
MKDIR = mkdir

# COLORS
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
RED		= \033[0;31m
RESET 	= \033[0m

CC = cc

LIBFT_DIR		= libraries/libft
PATH_BUILD		= build/
PATH_OBJECTS	= build/objs/
PATH_SOURCE		= src/
PATH_INIT		= src/init/
PATH_RESET		= src/reset/
PATH_LOOP		= src/shell_loop/
PATH_SIGNALS	= src/signals/
PATH_LEXER		= src/lexer/
PATH_PARSER		= src/parser/
PATH_BUILTINS	= src/builtins/
PATH_EXPANDER	= src/expander/
PATH_UTILS		= src/utils/
PATH_ERROR		= src/error/
PATH_PIPEX		= src/pipex/
PATH_EXECUTOR	= src/executor/

BUILD_PATHS = $(PATH_BUILD) $(PATH_OBJECTS)

FLAGS	=	-Wall -Werror -Wextra #-g -fsanitize=address

LIBFT	=	./libraries/libft/libft.a

ifeq ($(shell which brew 2>/dev/null),)
    READLINE_DIR = /usr
else
    READLINE_DIR = $(shell brew --prefix readline)
endif

READLINE_LIB = -lreadline -lhistory -L$(READLINE_DIR)/lib

READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib

src	=	$(PATH_SOURCE)/main.c					\
		$(PATH_INIT)/init_shell.c				\
		$(PATH_INIT)/init_env.c					\
		$(PATH_RESET)/reset_shell.c				\
		$(PATH_LOOP)/shell_loop.c				\
		$(PATH_ERROR)/error_msg.c				\
		$(PATH_ERROR)/error_handling.c			\
		$(PATH_SIGNALS)/signals.c				\
		$(PATH_LEXER)/lexer.c					\
		$(PATH_LEXER)/add_lexer.c				\
		$(PATH_LEXER)/del_lexer.c				\
		$(PATH_LEXER)/token.c					\
		$(PATH_LEXER)/handle_token.c			\
		$(PATH_LEXER)/word.c					\
		$(PATH_PARSER)/parser.c					\
		$(PATH_PARSER)/commands.c				\
		$(PATH_PARSER)/add_commands.c			\
		$(PATH_PARSER)/del_commands.c			\
		$(PATH_PARSER)/redirections.c			\
		$(PATH_BUILTINS)/builtins.c				\
		$(PATH_BUILTINS)/ft_cd.c 				\
		$(PATH_BUILTINS)/ft_echo.c				\
		$(PATH_BUILTINS)/ft_env.c				\
		$(PATH_BUILTINS)/ft_exit.c				\
		$(PATH_BUILTINS)/ft_export.c			\
		$(PATH_BUILTINS)/ft_pwd.c 				\
		$(PATH_BUILTINS)/ft_unset.c				\
		$(PATH_UTILS)/utils.c					\
		$(PATH_UTILS)/clean_utils.c				\
		$(PATH_UTILS)/path_utils.c				\
		$(PATH_UTILS)/env_utils.c				\
		$(PATH_UTILS)/quote_utils.c				\
		$(PATH_UTILS)/str_utils.c				\
		$(PATH_UTILS)/input_utils.c				\
		$(PATH_UTILS)/pipes_utils.c				\
		$(PATH_UTILS)/expander_utils.c			\
		$(PATH_UTILS)/heredoc_utils.c			\
		$(PATH_EXECUTOR)/executor.c				\
		$(PATH_EXECUTOR)/check_redirections.c	\
		$(PATH_EXECUTOR)/handle_cmd.c			\
		$(PATH_EXECUTOR)/heredoc.c				\
		$(PATH_EXPANDER)/expander.c				\
		$(PATH_EXPANDER)/expander_str.c			\
		$(PATH_EXPANDER)/dollar_sign.c			\
		$(PATH_EXPANDER)/question_mark.c		\

OBJS	=	$(addprefix $(PATH_OBJECTS), $(notdir $(patsubst %.c, %.o, $(src))))

HEADER	=	.includes/minishell.h	\
			.includes/color.h		\
			.includes/messages.h	\
			.includes/defines.h		\
			.includes/data.h		\
			.includes/utils.h		\
			.includes/error.h		\
			.includes/init.h		\
			.includes/reset.h		\
			.includes/signals.h		\
			.includes/builtins.h	\
			.includes/lexer.h		\
			.includes/parser.h		\
			.includes/executor.h	\
			.include/expander.h		\
	
INCLUDES =-Iincludes -I$(PATH_PIPEX) -I$(LIBFT_DIR) -I$(READLINE_DIR)/include 

all: $(BUILD_PATHS) $(NAME)

$(PATH_OBJECTS)%.o:: $(PATH_SOURCE)%.c
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_INIT)%.c
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_RESET)%.c
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_LOOP)%.c
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_SIGNALS)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_LEXER)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_PARSER)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_BUILTINS)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_EXPANDER)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_UTILS)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_ERROR)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(PATH_OBJECTS)%.o:: $(PATH_EXECUTOR)%.c $(HEADERS)
	@$(CC) -c $(FLAGS) $(INCLUDES) $< -o $@

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(READLINE_LIB) -o $(NAME)
	@echo "$(GREEN)$(NAME): $(NAME) has been created successfully!$(RESET)"

$(LIBFT):
	@$(MAKE) bonus -C ./libraries/libft --silent

$(PATH_BUILD):
	@$(MKDIR) $(PATH_BUILD)

$(PATH_OBJECTS):
	@$(MKDIR) $(PATH_OBJECTS)

clean:
	@echo "$(YELLOW)$(NAME): Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@rm -f $(PATH_BUILD).tmp*
	@rm -rf $(PATH_OBJECTS) $(PATH_BUILD)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent

fclean: clean
	@echo "$(YELLOW)$(NAME): Cleaning all files...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@echo "$(GREEN)$(NAME): All files have been cleaned!$(RESET)"

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re
