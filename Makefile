# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 06:19:29 by ymaaloum          #+#    #+#              #
#    Updated: 2024/09/19 07:17:52 by ymaaloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME1 = push_swap
NAME2 = checker
SRC1 =  mandatory/push_swap.c \
		mandatory/utils_err_1.c \
		mandatory/utils_err_2.c \
		mandatory/utils_err_3.c \
		mandatory/utils_move_1.c\
		mandatory/utils_move_2.c \
		mandatory/utils_sort_1.c \
		mandatory/utils_sort_2.c \
		mandatory/utils_sort_3.c \
		mandatory/utils_sort_4.c \

SRC2 = 	bonus/get_next_line/get_next_line.c\
		bonus/get_next_line/get_next_line_utils.c \
		bonus/checker_bonus.c \
		bonus/checker_utils_bonus.c \
		bonus/utils_err_1_bonus.c \
		bonus/utils_err_2_bonus.c \
		bonus/utils_err_3_bonus.c \
		bonus/utils_move_1_bonus.c \
		bonus/utils_move_2_bonus.c \



RESET		= 	\033[1;97m
GREEN 		= 	\033[1;32m
RED			= 	\033[1;31m



OBJ1			= 	$(SRC1:.c=.o)
OBJ1			:=	$(addprefix obj/, $(OBJ1))
OBJ_DIR1		= 	obj/ obj/mandatory/
OBJ2			= 	$(SRC2:.c=.o)
OBJ2			:=	$(addprefix obj_bonus/, $(OBJ2))
OBJ_DIR2		= 	obj_bonus/ obj_bonus/bonus/ obj_bonus/bonus/get_next_line


all: $(OBJ_DIR1) ${NAME1}

$(OBJ_DIR1):
			@echo "$(GREEN)$(OBJ_DIR1) : Created ! [^_^]$(RESET)"
			mkdir -p $(OBJ_DIR1)

${NAME1}: $(OBJ1)
	@${CC} ${CFLAGS} ${OBJ1} -o ${NAME1}
	@echo "$(GREEN)$(NAME1) : Created ! [^_^]$(RESET)"

obj/%.o: %.c
		$(CC) $(CFLAGS) -c  $< -o $@


$(OBJ_DIR2):
		@echo "$(GREEN)$(OBJ_DIR2) : Created ! [^_^]$(RESET)"
		mkdir -p $(OBJ_DIR2)

bonus: $(OBJ_DIR2) ${NAME2}

$(NAME2): $(OBJ2)
		@$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)
		@echo "$(GREEN)$(NAME2) : Created ! [^_^]$(RESET)"

obj_bonus/%.o: %.c
		$(CC) $(CFLAGS) -c  $< -o $@

clean:
		@rm -rf obj
		@rm -rf obj_bonus
		@echo "$(RED)$(NAME1) : file obj deleted ! [^_^]$(RESET)"
		@echo "$(RED)$(NAME2) : file obj deleted ! [^_^]$(RESET)"

fclean: clean
			@rm -f $(NAME1)
			@rm -f $(NAME2)
			@echo "$(RED)$(NAME1) : file obj and file executable deleted ! [^_^]$(RESET)"
			@echo "$(RED)$(NAME2) : file obj and file executable deleted ! [^_^]$(RESET)"
re: fclean all

