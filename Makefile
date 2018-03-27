#!/usr/bin/make -f

################################################################################
# SETTINGS                                                                     #
################################################################################

NAME = libmemshare.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCE_DIR = src
MEMSHARE_SRC = \
	create \
	delete \

MEMSHARE_OBJ = $(patsubst %, obj/%.o, $(MEMSHARE_SRC))
INC = -I inc

################################################################################
# COLORS                                                                       #
################################################################################

NC = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
BLUE = \033[1;36m

################################################################################
# RULES                                                                        #
################################################################################

all: $(NAME)

$(NAME): $(MEMSHARE_OBJ)
	@printf "$(YELLOW)%-50s$(NC)" "Building $@... "
	@ar rcs $(NAME) $(MEMSHARE_OBJ)
	@echo "$(GREEN)DONE$(NC)"

obj/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo " > Compiling $<..."
	@$(CC) $(OBJFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf obj
	@echo "$(RED)Object files removed$(NC)"

fclean: clean
	@rm -f $(MEMSHARE_OBJ)
	@rm -f $(NAME)
	@echo "$(BLUE) $(NAME) removed$(NC)"

re: fclean all