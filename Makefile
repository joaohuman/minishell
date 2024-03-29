# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 21:18:27 by aminoru-          #+#    #+#              #
#    Updated: 2023/02/20 11:09:02 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFTPATH = ./lib/libft/
LIBFT = ./lib/libft/libft.a
CC = gcc
READFLAGS = -lreadline -lncurses
CFLAG = -Wall -Werror -Wextra -g3
INCS = -I ./include/
SRCS = 	./src/main.c \
		./src/minishell.c \
		./src/env_to_lst.c \
		./src/print_list.c \
		./src/builtin_all.c \
		./src/signals.c \
		./src/have_cmd.c \
		./src/ft_add_history.c \
		./src/free_all.c \
		./src/status_error.c \
		./src/builtin_env.c \
		./src/builtin_export.c  \
		./src/builtin_unset.c  \
		./src/builtin_exit.c \
		./src/builtin_pwd.c \
		./src/builtin_echo.c \
		./src/builtin_cd.c \
		./src/take_value_of_env.c \
		./src/initialize_var.c \
		./src/tokenizer.c \
		./src/change_value_of_env.c \
		./src/builtin_other.c  \
		./src/redirect_verify.c  \
		./src/builtin_pipe_to_all.c \
		./src/here_doc.c \
		./src/verify_cmd.c \
		./src/here_doc_complement.c  \
		./src/builtin_pipe_to_all_complement.c  \
		./src/have_two_quotes.c \
		./src/split_quotes.c \
		./src/split_space_quotes.c \
		./src/tokenizer_complement.c \
		./src/free_table.c \
		./src/ft_strlen_pp.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} 
			make -C $(LIBFTPATH)
			${CC} -o ${NAME} ${CFLAG} ${OBJS} ${LIBFT} ${READFLAGS}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

clean:
			make clean -C ./lib/libft
			make clean -C ./test_minunit
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./lib/libft
			make fclean -C ./test_minunit
			rm -f ${NAME}

test:
			clear
			norminette -R CheckForbiddenSourceHeader ./src/ ./include/ ./lib/

val: $(NAME)
	make
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

re: fclean all

.PHONY: all clean fclean re
