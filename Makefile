# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madamou <madamou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 16:07:55 by madamou           #+#    #+#              #
#    Updated: 2024/12/16 02:44:11 by madamou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
PURPLE			=	\033[0;35m
END= 	$(shell tput -Txterm sgr0)

CC = cc
C_FLAGS = -Wall -Wextra -Werror -g3

OBJS_DIR = .objets/

GARBAGE = $(addprefix garbage_collector/, garbage.c lock_unlock.c garbage_utils.c)

EXPAND = $(addprefix expand/, expand.c utils.c env.c)

SRCS = main.c $(GARBAGE) $(EXPAND)

SRCS := $(SRCS:%=./%)

OBJS = $(SRCS:./%.c=$(OBJS_DIR)/%.o)

DIR_DUP = mkdir -p $(@D)

G				= $(GREEN)
X 				= $(END)
BAR_SIZE		= 50

TOTAL_FILES		:= $(words $(SRCS))
COMPILED_FILES	:= 0

NAME = a.out

LIBFT = libft.a

all: $(LIBFT) $(NAME)

$(LIBFT) :
	@make -C libft

$(NAME): $(OBJS)
	@$(CC) $(C_FLAGS) $^ -L libft -lft -o $@
	@echo
	@echo "✅$(GREEN)garbage compiled >_$(END)✅"
$(OBJS_DIR)/%.o : %.c
	@$(DIR_DUP)
	@$(CC) $(C_FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
	@echo -n ""
	@for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "$(G)▰$(X)" ; \
	done
	@for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
		echo -n "▱" ; \
	done
	@echo -n " [$(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%] "
# @echo -n ""
# @printf "%d/%d" $(COMPILED_FILES) $(TOTAL_FILES)
# @echo -n " "
# @printf "%s" $(notdir $<)
	@printf "\e[0K\r"


%.o : %.c
	$(CC) $(C_FLAGS) -c -include ./libft.h $< -o $@

clean:
	@make clean -C libft
	@rm -rf $(OBJS_DIR)
                                                                             
fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
